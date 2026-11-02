#include "native_addresses.h"

// Shared service callbacks. Pointer names/types are inferred from the observed fixed-width accesses.
// The uint return views retain physical EAX residue; the original callback return declarations are unavailable.

// Copies two 16-byte activation results before publishing success, or publishes the reply reason before failure.
// R6GameService.dll @ 1000dc00 : stdcall/RET16; reply BYTE+4 is success, WORD+6 is reason; second word is unused.
uint __stdcall ReceiveActivationReply(const byte *reply,uint unusedSecond,const uint *firstBlock,const uint *secondBlock)
{
  uint active = *(uint *)R6GameServiceAddresses::GActivationState;
  uint rawEax = *(uint *)R6GameServiceAddresses::GServiceVerboseLogging;
  using LogABI = uint (__cdecl *)(FOutputDevice *,const TCHAR *,...); // Raw EAX view of the void Logf import.
  if (active == 0) {
    if (rawEax != 0)
      return (*(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot)
          (GLog,(const TCHAR *)R6GameServiceAddresses::WideTextCallbackIgnoreResultsFromRcvActivationID);
    return rawEax;
  }
  const byte *response = reply;
  if (rawEax != 0) {
    uint reason = *(const ushort *)(response + 6);
    rawEax = (*(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot)
        (GLog,(const TCHAR *)R6GameServiceAddresses::WideTextCallbackRcvActivationIDErrorI,reason);
  }
  // The native rereads success after diagnostics and replaces only AL, retaining the other EAX bytes on failure.
  byte success = response[4];
  rawEax = (rawEax & 0xffffff00) | success;
  if (success != 0) {
    const uint *source = firstBlock;
    *(uint *)0x100933e4 = source[0];
    *(uint *)0x100933e8 = source[1];
    rawEax = source[2];
    *(uint *)0x100933ec = rawEax;
    uint lastFirstWord = source[3];
    source = secondBlock;
    *(uint *)0x100933f0 = lastFirstWord;
    *(uint *)0x10093418 = source[0];
    *(uint *)0x1009341c = source[1];
    rawEax = source[2];
    *(uint *)0x10093420 = rawEax;
    *(uint *)0x10093424 = source[3];
    *(uint *)R6GameServiceAddresses::GActivationState = 6;
  } else {
    uint reason = *(const ushort *)(response + 6);
    *(uint *)0x100933f4 = reason;
    *(uint *)R6GameServiceAddresses::GActivationState = 3;
  }
  return rawEax;
}

// Publishes authorization success before its 20-byte copy, or failure before reading/storing the reason.
// R6GameService.dll @ 1000dcd0 : stdcall/RET12; inactive calls never read the reply or result buffers.
uint __stdcall ReceiveAuthorizationReply(const byte *reply,uint unusedSecond,const uint *result)
{
  uint active = *(uint *)R6GameServiceAddresses::GAuthorizationState;
  uint rawEax = *(uint *)R6GameServiceAddresses::GServiceVerboseLogging;
  using LogABI = uint (__cdecl *)(FOutputDevice *,const TCHAR *,...); // Raw EAX view of the void Logf import.
  if (active == 0) {
    if (rawEax != 0)
      return (*(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot)
          (GLog,(const TCHAR *)R6GameServiceAddresses::WideTextCallbackIgnoreResultsFromRcvAuthorizationID);
    return rawEax;
  }
  const byte *response = reply;
  if (rawEax != 0) {
    uint reason = *(const ushort *)(response + 6);
    uint loggedSuccess = response[4];
    rawEax = (*(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot)
        (GLog,(const TCHAR *)R6GameServiceAddresses::WideText1CallbackRcvAuthorizationIDSuccessXErrorIdD,
         loggedSuccess,reason);
  }
  byte success = response[4];
  rawEax = (rawEax & 0xffffff00) | success;
  if (success != 0) {
    const uint *source = result;
    *(uint *)R6GameServiceAddresses::GAuthorizationState = 6;
    *(uint *)0x10093428 = source[0];
    *(uint *)0x1009342c = source[1];
    *(uint *)0x10093430 = source[2];
    *(uint *)0x10093434 = source[3];
    rawEax = source[4];
    *(uint *)0x10093438 = rawEax;
  } else {
    *(uint *)R6GameServiceAddresses::GAuthorizationState = 7;
    uint reason = *(const ushort *)(response + 6);
    *(uint *)0x10093414 = reason;
  }
  return rawEax;
}
