#include "native_addresses.h"
#include "native_records.h"

// Native status-word throw support; TypeDescriptor8c270 names ATL::CAtlException, with no invented class declaration.
// R6GameService.dll data @ 1007b73c : native storage identity retained.
const R6GameServiceNative::CatchableType GAtlStatusCatchableType = {
  0,
  R6GameServiceAddresses::CAtlExceptionATLTypeDescriptor,
  0,
  -1,
  0,
  4,
  0,
};
// R6GameService.dll data @ 1007b758 : native storage identity retained.
const R6GameServiceNative::CatchableTypeArray<1> GAtlStatusCatchableArray = {
  1,
  {R6GameServiceAddresses::GAtlStatusCatchableType},
};
// R6GameService.dll data @ 1007b760 : native storage identity retained.
const R6GameServiceNative::ThrowInfo GAtlStatusThrowInfo = {0, 0, 0, R6GameServiceAddresses::GAtlStatusCatchableArray};

// Throws the caller status word as ATL::CAtlException through the selected ThrowInfo.
// R6GameService.dll @ 100051f0 : complete native control/access order and raw ABI retained.
__declspec(naked) [[noreturn]] void __cdecl ThrowAtlStatus(LONG status)
{
  __asm {
    // Rewrite the caller argument from its initial value, then throw that four-byte slot through native33a16.
    mov    eax,DWORD PTR [esp+0x4]
    push   offset GAtlStatusThrowInfo
    lea    ecx,[esp+0x8]
    push   ecx
    mov    DWORD PTR [esp+0xc],eax
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Throws the current last-error word, mapping only positive signed values into Win32 HRESULT form.
// R6GameService.dll @ 10036e40 : complete native control/access order and raw ABI retained.
__declspec(naked) [[noreturn]] void RaiseWin32LastErrorAsHResult(void)
{
  __asm {
    // GetLastError interpreted signed for gate; zero/high-bit values pass unchanged, only positive values mask16/set80070000.
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_GetLastErrorSlot
    test   eax,eax
    jle    Branch1
    and    eax,0xffff
    or     eax,0x80070000
  Branch1:
    push   eax
    call   R6GameServiceAddresses::ThrowAtlStatus
  }
}
