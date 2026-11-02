#include "native_addresses.h"
#include "native_records.h"

// R6GameService.dll data @ 100811c0 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo RandomStackMD5ExceptionHandlerFunctionInfo;

// Shared native tail frame for random-byte generation and RSA seed updating.
struct NativeStackMD5Frame {
  uint context[29]; // EntryESP-0x80..-0x0d in both parents.
  void *previousExceptionList;
  void *handler;
  uint state;
};

struct RandomBytesDigestFrame {
  byte unusedPrefix[3];
  byte previousCounterByte; // EntryESP-0x81, used during the native counter propagation loop.
  NativeStackMD5Frame md5;
};

// Generates buffered bytes using a stack MD5 context; seed-needed failure returns1 without touching output.
// R6GameService.dll @ 1003daf0 : ECX context unused, output/mutable-count/state words, RET0x0c; EAX=0 or1.
uint __thiscall GenerateCryptoRandomBytes(void *unusedContext,byte *output,uint byteCount,uint *stateArgument)
{
  RandomBytesDigestFrame frame;
  frame.md5.state = 0xffffffff;
  frame.md5.handler = (void *)RandomStackMD5ExceptionHandler;
  frame.md5.previousExceptionList = ExceptionList;
  ExceptionList = &frame.md5.previousExceptionList;
  ConstructMd5Context(frame.md5.context,1);
  uint *state = stateArgument;
  frame.md5.state = 0;
  if (state[0] != 0) {
    frame.md5.state = 0xffffffff;
    DestroyMD5(frame.md5.context);
    ExceptionList = frame.md5.previousExceptionList;
    return 1;
  }
  uint available = state[5];
  uint requested = byteCount;
  byte *destination = output;
  if (requested > available) {
    do {
      const byte *source = (const byte *)((uint)state + 0x28 - available);
      for (uint offset = 0; offset < (available & ~3U); offset += 4) {
        *(uint *)(destination + offset) = *(const uint *)(source + offset);
      }
      byte *oldDestination = destination;
      destination = (byte *)((uint)destination + available);
      for (uint offset = available & ~3U; offset < available; ++offset) oldDestination[offset] = source[offset];
      byteCount = byteCount - available;
      UpdateMD5(frame.md5.context,(const byte *)(state + 1),16);
      FinalizeMD5(frame.md5.context,state + 6);
      available = 16;
      byte *counterByte = (byte *)state + 0x13;
      for (uint propagated = 0; propagated < 16; ++propagated) {
        frame.previousCounterByte = *counterByte;
        *counterByte = (byte)(frame.previousCounterByte + 1);
        // The old zero byte propagates; an old ff byte wraps to0 and stops.
        if (frame.previousCounterByte != 0) break;
        --counterByte;
      }
      requested = byteCount;
    } while (requested > 16);
  }
  const byte *source = (const byte *)((uint)state + 0x28 - available);
  for (uint offset = 0; offset < (requested & ~3U); offset += 4) {
    *(uint *)(destination + offset) = *(const uint *)(source + offset);
  }
  uint remaining = available - requested;
  frame.md5.state = 0xffffffff; // Native cleanup is disabled before the residual byte copy.
  for (uint offset = requested & ~3U; offset < requested; ++offset) destination[offset] = source[offset];
  state[5] = remaining;
  DestroyMD5(frame.md5.context);
  ExceptionList = frame.md5.previousExceptionList;
  return 0;
}

// Tail-forwards an ECX stack hash context to the MD5 destructor helper without changing its raw return.
// R6GameService.dll @ 1003dc30 : ECX context, no stack words, JMP1003c0a0; not an initializer.
__declspec(naked) uint __fastcall ForwardStackMD5ContextCleanup(void *context)
{
  __asm { jmp R6GameServiceAddresses::DestroyMD5 }
}

// Forwards the stack context shared by native random-byte generation and seed-update unwind maps.
// R6GameService.dll @ 10066b80 : inherited EBP-0x80 context address, JMP1003dc30.
__declspec(naked) void __cdecl CleanupRandomStackMD5Context(void)
{
  __asm {
    lea    ecx,[ebp-0x80]
    jmp    R6GameServiceAddresses::ForwardStackMD5ContextCleanup
  }
}

// Selects the one-state stack-context cleanup map shared by1003daf0 and1003dc60.
// R6GameService.dll @ 10066b88 : EAX=100811c0, inherited-frame JMP10033906.
__declspec(naked) void __cdecl RandomStackMD5ExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::RandomStackMD5ExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}
