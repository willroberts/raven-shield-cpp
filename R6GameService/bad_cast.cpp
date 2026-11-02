#include "native_addresses.h"
#include "native_records.h"

// Imported global bad_cast members; selected decorated import names establish class ownership.

// Forwards the ECX bad_cast destination and original source reference to the imported copy constructor.
// R6GameService.dll @ 10033a28 : complete six-byte native current-IAT tail, no wrapper frame.
__declspec(naked) __thiscall bad_cast::bad_cast(const bad_cast &source)
{
  __asm {
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCR71__Constructbad_castSlot2
  }
}

// Forwards the ECX bad_cast object directly to its current imported destructor.
// R6GameService.dll @ 10033a2e : complete six-byte native current-IAT tail, no wrapper frame.
__declspec(naked) __thiscall bad_cast::~bad_cast(void)
{
  __asm {
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCR71__Destroybad_castSlot
  }
}

// R6GameService.dll data @ 1007aba0 : bad_cast/exception size12 typed copy/destruction metadata.
const R6GameServiceNative::CatchableType GBadCastThrowData = {
  0x0,
  R6GameServiceAddresses::exceptionTypeDescriptor,
  0x0,
  -1,
  0x0,
  0xc,
  R6GameServiceAddresses::exception_exception,
};

// R6GameService.dll data @ 1007abbc : bad_cast/exception size12 typed copy/destruction metadata.
const R6GameServiceNative::CatchableType bad_castGBadCastThrowData = {
  0x0,
  R6GameServiceAddresses::bad_castTypeDescriptor,
  0x0,
  -1,
  0x0,
  0xc,
  R6GameServiceAddresses::bad_cast_bad_cast,
};

// R6GameService.dll data @ 1007abd8 : bad_cast/exception size12 typed copy/destruction metadata.
// R6GameService.dll data @ 1007aba0 : native storage identity retained.
const R6GameServiceNative::CatchableTypeArray<2> bad_castGBadCastThrowData2 = {
  0x2,
  {R6GameServiceAddresses::bad_castGBadCastThrowData, R6GameServiceAddresses::GBadCastThrowData},
};

// R6GameService.dll data @ 1007abe4 : bad_cast/exception size12 typed copy/destruction metadata.
// R6GameService.dll data @ 1007abd8 : native storage identity retained.
const R6GameServiceNative::ThrowInfo bad_castGBadCastThrowData3 = {
  0x0,
  R6GameServiceAddresses::bad_cast__bad_cast,
  0x0,
  R6GameServiceAddresses::bad_castGBadCastThrowData2,
};
