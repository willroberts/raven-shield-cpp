#include "native_symbols.hpp"
// Selected native engine/message loop, benchmark output and guarded cleanup.
#include "cpp_exception_metadata.hpp"
#include "object_support.hpp"
#include "container_support.hpp"
#include "launcher_math.hpp"
#include "timing_support.hpp"
#include "package_saving.hpp"
#include "launch_runtime.hpp"
#include <windows.h>
#include <new>

class WLog;
class FExec;
class FStats;
class FEngineStats;
class FFileManager;
class USubsystem;
class WTerminal;
class FOutputDevice;
class UViewport;
extern WLog *GLogWindow;
extern FExec *GExec;
extern UEngine *g_pEngine;
extern USubsystem *GWindowManager;
extern FStats GStats;
extern FEngineStats GEngineStats;
extern FFileManager *GFileManager;
extern int32_t GIsRunning, GIsRequestingExit, GIsEditor, GUnicodeOS, GScriptCycles;
extern const char16_t g_configEmptyString[];
extern const double g_execHookNoPlayerDistance;
extern const uint16_t *__cdecl appCmdLine();
extern int32_t __cdecl ParseParam(const uint16_t *stream, const uint16_t *parameter);
extern void __cdecl appUnwindf(const uint16_t *format, ...);
extern void __cdecl appRequestExit(int32_t force);
extern void __cdecl appRandInit(int32_t seed);
extern int32_t __cdecl appRand();
extern void __cdecl appSleep(float seconds);
extern int32_t __cdecl appSprintf(uint16_t *destination, const uint16_t *format, ...);
extern int32_t __cdecl appSaveStringToFile(const FString &text, const uint16_t *filename, FFileManager *manager);
extern int32_t __cdecl appLoadFileToString(FString &text, const uint16_t *filename, FFileManager *manager);

// RavenShield.exe data @ 1091f0dc : g_mainLoopPreviouslyFocused
int32_t g_mainLoopPreviouslyFocused = 1;         // Persistent across loop invocations, not reset at entry.
extern const double g_detailCpuSecondsThreshold; // Shared native 1.0 constant, canonical in detail page.
// RavenShield.exe data @ 10916668 : g_mainLoopGuardName
const char16_t g_mainLoopGuardName[] = u"MainLoop";
// RavenShield.exe data @ 1091667c : g_mainLoopExitGuardName
const char16_t g_mainLoopExitGuardName[] = u"ExitMainLoop";
// RavenShield.exe data @ 10916698 : g_mainLoopBenchmarkSummary
const char16_t g_mainLoopBenchmarkSummary[] = u"\n%f fps          rand[%i]";
// RavenShield.exe data @ 109166cc : g_mainLoopBenchmarkLog
const char16_t g_mainLoopBenchmarkLog[] = u"Benchmark.log";
// RavenShield.exe data @ 109166e8 : g_mainLoopStatsFilename
const char16_t g_mainLoopStatsFilename[] = u"stats%05i.csv";
// RavenShield.exe data @ 10916704 : g_mainLoopShotCommand
const char16_t g_mainLoopShotCommand[] = u"shot";
// RavenShield.exe data @ 10916710 : g_mainLoopThrottleGuardName
const char16_t g_mainLoopThrottleGuardName[] = u"ThrottleEditor";
// RavenShield.exe data @ 10916730 : g_mainLoopMessagePumpGuardName
const char16_t g_mainLoopMessagePumpGuardName[] = u"MessagePump";
// RavenShield.exe data @ 10916748 : g_mainLoopDispatchGuardName
const char16_t g_mainLoopDispatchGuardName[] = u"DispatchMessage";
// RavenShield.exe data @ 10916768 : g_mainLoopMessageContext
const char16_t g_mainLoopMessageContext[] = u"%08X %i";
// RavenShield.exe data @ 10916778 : g_mainLoopTranslateGuardName
const char16_t g_mainLoopTranslateGuardName[] = u"TranslateMessage";
// RavenShield.exe data @ 1091679c : g_mainLoopTickRateGuardName
const char16_t g_mainLoopTickRateGuardName[] = u"EnforceTickRate";
// RavenShield.exe data @ 109167bc : g_mainLoopWorldGuardName
const char16_t g_mainLoopWorldGuardName[] = u"UpdateWorld";
// RavenShield.exe data @ 109167e0 : g_mainLoopMovieParameter
const char16_t g_mainLoopMovieParameter[] = u"RECORDMOVIE";
// RavenShield.exe data @ 109167f8 : g_mainLoopBenchmarkParameter
const char16_t g_mainLoopBenchmarkParameter[] = u"BENCHMARK";
// RavenShield.exe data @ 1091680c : g_mainLoopEnterGuardName
const char16_t g_mainLoopEnterGuardName[] = u"EnterMainLoop";
// RavenShield.exe data @ 10916828 : g_mainLoopEngineExpression
const char g_mainLoopEngineExpression[] = "Engine";

// RavenShield.exe @ 109092c0 : MainLoop
// Run native engine/window ticks, message dispatch, editor throttling and optional benchmark/movie recording.
void __cdecl MainLoop(UEngine *engine)
{
  // Bind the import slot; entry/exit guards contain both actual target reads.
  const auto &setExec =
      *reinterpret_cast<void(__thiscall **)(WTerminal *, FExec *)>(NativeAddress(NativeImport_WTerminal_SetExec));
  const auto tick = [](auto &object, float delta)
  {
    auto *receiver = object;
    auto *dispatchObject = object;
    const uint32_t table = *reinterpret_cast<const uint32_t *>(dispatchObject);
    const auto invoke = *reinterpret_cast<void(__thiscall **)(void *, float)>(table + 0x64);
    invoke(receiver, delta);
  };
  // Inline source representation of each unrolled native cubemap-reference test; re-fetch after imported calls.
  const auto clearCubemap = [](auto &objects, uint32_t offset)
  {
    if (*reinterpret_cast<UObject **>(reinterpret_cast<uint8_t *>(*objects) + offset))
    {
      const auto cubeClass =
          *reinterpret_cast<UClass *(__cdecl **)()>(NativeAddress(NativeImport_UCubemap_StaticClass));
      UClass *type = cubeClass();
      UObject *material = *reinterpret_cast<UObject **>(reinterpret_cast<uint8_t *>(*objects) + offset);
      const auto isA =
          *reinterpret_cast<int32_t(__thiscall **)(UObject *, UClass *)>(NativeAddress(NativeImport_UObject_IsA));
      if (isA(material, type)) *reinterpret_cast<UObject **>(reinterpret_cast<uint8_t *>(*objects) + offset) = nullptr;
    }
  };
  try
  {
    if (!engine) appFailAssert(g_mainLoopEngineExpression, g_unEngineWinSourcePath, 0x3a0);
    g_pEngine = engine;
    try
    {
      if (GLogWindow)
      {
        FExec *exec = engine ? reinterpret_cast<FExec *>(reinterpret_cast<uint32_t>(engine) + 0x2cu) : nullptr;
        setExec(reinterpret_cast<WTerminal *>(GLogWindow), exec);
      }
    }
    // RavenShield.exe @ 10909358 : RethrowMainLoopEnterPointer
    // Copy-throw the caught UTF-16 pointer through the native guard's dedicated throw slot.
    catch (uint16_t *error)
    {
      throw error;
    }
    // RavenShield.exe @ 10909372 : UnwindMainLoopEnterFailure
    // Append this guard's context and rethrow the active exception without extra rollback.
    catch (...)
    {
      appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
                 reinterpret_cast<const uint16_t *>(g_mainLoopEnterGuardName));
      throw;
    }
    GIsRunning = 1;
    const DWORD threadId = GetCurrentThreadId();
    const HANDLE thread = GetCurrentThread(); // Pseudo-handle is neither owned nor closed here.
    double oldTime = ReadTimestampSeconds();
    double secondStart = oldTime;
    int32_t ticks = 0;
    const int32_t benchmarking =
        ParseParam(appCmdLine(), reinterpret_cast<const uint16_t *>(g_mainLoopBenchmarkParameter));
    int32_t frames = 0;
    const int32_t discardedFrames = 10, maximumFrames = 3300;
    float benchmarkSeconds = 0.0f;
    TArray<FString> records;
    for (int32_t i = 0; i < maximumFrames - discardedFrames + 1; ++i)
    {
      void *slot = AllocateStringArraySlot(12, &records);
      if (slot) new (slot) FString(reinterpret_cast<const uint16_t *>(g_configEmptyString));
    }
    if (benchmarking) appRandInit(0);
    const int32_t recordingMovie =
        ParseParam(appCmdLine(), reinterpret_cast<const uint16_t *>(g_mainLoopMovieParameter));
    void *renderer = *reinterpret_cast<void **>(reinterpret_cast<uint8_t *>(engine) + 0x4c);
    if (*reinterpret_cast<const int32_t *>(reinterpret_cast<const uint8_t *>(renderer) + 0x54) == 0)
    {
      for (TObjectIterator<UModifier> materials; materials; ++materials) clearCubemap(materials, 0x58);
      for (TObjectIterator<UCombiner> materials; materials; ++materials)
      {
        clearCubemap(materials, 0x60);
        clearCubemap(materials, 0x64);
      }
      for (TObjectIterator<UShader> materials; materials; ++materials)
      {
        clearCubemap(materials, 0x60);
        clearCubemap(materials, 0x64);
        clearCubemap(materials, 0x68);
        clearCubemap(materials, 0x6c);
        clearCubemap(materials, 0x70);
        clearCubemap(materials, 0x74);
        clearCubemap(materials, 0x78);
      }
    }
    MSG message;
    while (GIsRunning && !GIsRequestingExit)
    {
      const auto clearStats =
          *reinterpret_cast<void(__thiscall **)(FStats *)>(NativeAddress(NativeImport_FStats_Clear));
      clearStats(&GStats);
      const uint32_t startCycles = static_cast<uint32_t>(ReadTimestampCounter());
      if (benchmarking)
      {
        if (frames == discardedFrames)
          benchmarkSeconds = 0.0f;
        else if (frames > maximumFrames)
          appRequestExit(0); // Finish this native iteration before retesting exit.
      }
      try
      {
        double newTime;
        float delta;
        // Preserve the native double snapshot while subtracting oldTime from the still-extended x87 return.
        __asm {
          call ReadTimestampSeconds
          fst qword ptr [newTime]
          fsub qword ptr [oldTime]
          fstp dword ptr [delta]
        }
        if ((*reinterpret_cast<const uint32_t *>(reinterpret_cast<const uint8_t *>(engine) + 0x120) & 0x10000) != 0)
        {
          tick(engine, *reinterpret_cast<const float *>(reinterpret_cast<const uint8_t *>(engine) + 0x224));
          if (GWindowManager)
            tick(GWindowManager, *reinterpret_cast<const float *>(reinterpret_cast<const uint8_t *>(engine) + 0x224));
          const auto takeShot = *reinterpret_cast<void(__cdecl **)(UEngine *)>(NativeAddress(NativeImport_AVITakeShot));
          takeShot(engine);
        }
        else if (benchmarking || recordingMovie)
        {
          tick(engine, 1.0f / 30.0f);
          if (GWindowManager) tick(GWindowManager, 1.0f / 30.0f);
          if (frames < maximumFrames) benchmarkSeconds += delta;
          frames = static_cast<int32_t>(static_cast<uint32_t>(frames) + 1u);
        }
        else
        {
          tick(engine, delta);
          if (GWindowManager) tick(GWindowManager, delta);
        }
        ticks = static_cast<int32_t>(static_cast<uint32_t>(ticks) + 1u);
        oldTime = newTime;
        if (secondStart + g_detailCpuSecondsThreshold < oldTime)
        {
          *reinterpret_cast<float *>(reinterpret_cast<uint8_t *>(engine) + 0x8c) =
              static_cast<float>(static_cast<double>(ticks) / (oldTime - secondStart));
          secondStart = oldTime;
          ticks = 0;
        }
      }
      // RavenShield.exe @ 10909a65 : RethrowMainLoopWorldPointer
      // Copy-throw the caught UTF-16 pointer through the native guard's dedicated throw slot.
      catch (uint16_t *error)
      {
        throw error;
      }
      // RavenShield.exe @ 10909a82 : UnwindMainLoopWorldFailure
      // Append this guard's context and rethrow the active exception without extra rollback.
      catch (...)
      {
        appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
                   reinterpret_cast<const uint16_t *>(g_mainLoopWorldGuardName));
        throw;
      }
      try
      {
        if (!benchmarking)
        {
          const uint32_t table = *reinterpret_cast<const uint32_t *>(engine);
          const auto maxRate = *reinterpret_cast<float(__thiscall **)(UEngine *)>(table + 0xac);
          const float rate = maxRate(engine);
          if (rate > g_execHookNoPlayerDistance)
          {
            float delay;
            __asm {
              call ReadTimestampSeconds
              fsub qword ptr [oldTime]
              fld dword ptr [rate]
              fdivr qword ptr [g_detailCpuSecondsThreshold]
              fsubrp st(1), st
              fstp dword ptr [delay]
            }
            appSleep(MaxFloat(0.0f, delay));
          }
        }
      }
      // RavenShield.exe @ 10909b1d : RethrowMainLoopTickRatePointer
      // Copy-throw the caught UTF-16 pointer through the native guard's dedicated throw slot.
      catch (uint16_t *error)
      {
        throw error;
      }
      // RavenShield.exe @ 10909b3a : UnwindMainLoopTickRateFailure
      // Append this guard's context and rethrow the active exception without extra rollback.
      catch (...)
      {
        appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
                   reinterpret_cast<const uint16_t *>(g_mainLoopTickRateGuardName));
        throw;
      }
      try
      {
        for (;;)
        {
          const int32_t present =
              GUnicodeOS ? PeekMessageW(&message, nullptr, 0, 0, 1) : PeekMessageA(&message, nullptr, 0, 0, 1);
          if (!present) break;
          if (message.message == WM_QUIT)
          {
            if (GIsEditor) SaveDirtyPackages(engine);
            GIsRequestingExit = 1;
          }
          try
          {
            TranslateMessage(&message); // WM_QUIT is still translated and dispatched.
          }
          // RavenShield.exe @ 10909bf0 : RethrowMainLoopTranslatePointer
          // Copy-throw the caught UTF-16 pointer through the native guard's dedicated throw slot.
          catch (uint16_t *error)
          {
            throw error;
          }
          // RavenShield.exe @ 10909c0d : UnwindMainLoopTranslateFailure
          // Append this guard's context and rethrow the active exception without extra rollback.
          catch (...)
          {
            appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
                       reinterpret_cast<const uint16_t *>(g_mainLoopTranslateGuardName));
            appUnwindf(reinterpret_cast<const uint16_t *>(g_mainLoopMessageContext),
                       reinterpret_cast<uint32_t>(message.hwnd), static_cast<int32_t>(message.message));
            throw;
          }
          try
          {
            if (GUnicodeOS)
              DispatchMessageW(&message);
            else
              DispatchMessageA(&message);
          }
          // RavenShield.exe @ 10909c85 : RethrowMainLoopDispatchPointer
          // Copy-throw the caught UTF-16 pointer through the native guard's dedicated throw slot.
          catch (uint16_t *error)
          {
            throw error;
          }
          // RavenShield.exe @ 10909ca2 : UnwindMainLoopDispatchFailure
          // Append this guard's context and rethrow the active exception without extra rollback.
          catch (...)
          {
            appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
                       reinterpret_cast<const uint16_t *>(g_mainLoopDispatchGuardName));
            appUnwindf(reinterpret_cast<const uint16_t *>(g_mainLoopMessageContext),
                       reinterpret_cast<uint32_t>(message.hwnd), static_cast<int32_t>(message.message));
            throw;
          }
        }
      }
      // RavenShield.exe @ 10909ce8 : RethrowMainLoopMessagePumpPointer
      // Copy-throw the caught UTF-16 pointer through the native guard's dedicated throw slot.
      catch (uint16_t *error)
      {
        throw error;
      }
      // RavenShield.exe @ 10909d05 : UnwindMainLoopMessagePumpFailure
      // Append this guard's context and rethrow the active exception without extra rollback.
      catch (...)
      {
        appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
                   reinterpret_cast<const uint16_t *>(g_mainLoopMessagePumpGuardName));
        throw;
      }
      if (GIsEditor)
      {
        try
        {
          const int32_t focused = GetWindowThreadProcessId(GetForegroundWindow(), nullptr) == threadId ? 1 : 0;
          if (g_mainLoopPreviouslyFocused && !focused)
            SetThreadPriority(thread, -1);
          else if (focused && !g_mainLoopPreviouslyFocused)
            SetThreadPriority(thread, 0);
          if (!focused) Sleep(0);
          g_mainLoopPreviouslyFocused = focused;
        }
        // RavenShield.exe @ 10909db5 : RethrowMainLoopThrottlePointer
        // Copy-throw the caught UTF-16 pointer through the native guard's dedicated throw slot.
        catch (uint16_t *error)
        {
          throw error;
        }
        // RavenShield.exe @ 10909dd2 : UnwindMainLoopThrottleFailure
        // Append this guard's context and rethrow the active exception without extra rollback.
        catch (...)
        {
          appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
                     reinterpret_cast<const uint16_t *>(g_mainLoopThrottleGuardName));
          throw;
        }
      }
      if (recordingMovie && frames > 120)
      {
        auto *client = *reinterpret_cast<uint8_t **>(reinterpret_cast<uint8_t *>(engine) + 0x44);
        auto &viewports = *reinterpret_cast<TArray<UViewport *> *>(client + 0x30);
        auto *viewportExec = reinterpret_cast<FExec *>(reinterpret_cast<uint32_t>(viewports(0)) + 0x30u);
        const uint32_t logSlot = *reinterpret_cast<const uint32_t *>(NativeAddress(NativeImport_GLog));
        FOutputDevice *log = *reinterpret_cast<FOutputDevice **>(logSlot);
        const uint32_t table = *reinterpret_cast<const uint32_t *>(viewportExec);
        using ExecCommand = int32_t(__thiscall *)(FExec *, const uint16_t *, FOutputDevice *);
        const auto exec = *reinterpret_cast<const ExecCommand *>(table);
        exec(viewportExec, reinterpret_cast<const uint16_t *>(g_mainLoopShotCommand), log);
      }
      auto &stats = *reinterpret_cast<TArray<int32_t> *>(reinterpret_cast<uint8_t *>(&GStats) + 0x1c);
      const int32_t frameIndex =
          *reinterpret_cast<const int32_t *>(reinterpret_cast<const uint8_t *>(&GEngineStats) + 4);
      int32_t &frameCycles = stats(frameIndex);
      frameCycles = static_cast<int32_t>(static_cast<uint32_t>(ReadTimestampCounter()) - startCycles);
      const int32_t scriptIndex =
          *reinterpret_cast<const int32_t *>(reinterpret_cast<const uint8_t *>(&GEngineStats) + 0xfc);
      int32_t &scriptCycles = stats(scriptIndex);
      scriptCycles = GScriptCycles;
      GScriptCycles = 0;
      if (benchmarking)
      {
        const auto &update = *reinterpret_cast<void(__thiscall **)(FStats *, FString &, int32_t)>(
            NativeAddress(NativeImport_FStats_UpdateString));
        if (frames == 1)
          update(&GStats, records(0), 1);
        else
        {
          const int32_t row =
              ClampSigned(static_cast<int32_t>(static_cast<uint32_t>(frames) - static_cast<uint32_t>(discardedFrames)),
                          2, maximumFrames - discardedFrames);
          update(&GStats, records(row - 1), 0);
        }
      }
    }
    GIsRunning = 0;
    if (benchmarking)
    {
      const int32_t sampleFrames = maximumFrames - discardedFrames;
      FString report(reinterpret_cast<const uint16_t *>(g_configEmptyString));
      for (int32_t i = 0; i < sampleFrames; ++i) report += records(i);
      uint16_t filename[64];
      for (int32_t i = 0; i < 65536; ++i)
      {
        appSprintf(filename, reinterpret_cast<const uint16_t *>(g_mainLoopStatsFilename), i);
        FFileManager *receiver = GFileManager;
        FFileManager *dispatchManager = GFileManager;
        const uint32_t table = *reinterpret_cast<const uint32_t *>(dispatchManager);
        using QueryFileSize = int32_t(__thiscall *)(FFileManager *, const uint16_t *);
        const auto query = *reinterpret_cast<const QueryFileSize *>(table + 0x0c);
        if (query(receiver, filename) < 0) break;
      }
      appSaveStringToFile(report, filename, GFileManager); // If every candidate exists, reuse stats65535.csv.
      report = reinterpret_cast<const uint16_t *>(g_configEmptyString);
      appLoadFileToString(report, reinterpret_cast<const uint16_t *>(g_mainLoopBenchmarkLog), GFileManager);
      const int32_t random = appRand();
      {
        const double fps = static_cast<double>(sampleFrames) / static_cast<double>(benchmarkSeconds);
        FString summary = FString::Printf(reinterpret_cast<const uint16_t *>(g_mainLoopBenchmarkSummary), fps, random);
        report += summary;
      }
      appSaveStringToFile(report, reinterpret_cast<const uint16_t *>(g_mainLoopBenchmarkLog), GFileManager);
    }
    try
    {
      if (GLogWindow) setExec(reinterpret_cast<WTerminal *>(GLogWindow), nullptr);
      GExec = nullptr;
    }
    // RavenShield.exe @ 1090a110 : RethrowMainLoopExitPointer
    // Copy-throw the caught UTF-16 pointer through the native guard's dedicated throw slot.
    catch (uint16_t *error)
    {
      throw error;
    }
    // RavenShield.exe @ 1090a12d : UnwindMainLoopExitFailure
    // Append this guard's context and rethrow the active exception without extra rollback.
    catch (...)
    {
      appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
                 reinterpret_cast<const uint16_t *>(g_mainLoopExitGuardName));
      throw;
    }
  } // records is destroyed before the outer guard, also when nested guards rethrow.
  // RavenShield.exe @ 1090a15a : RethrowMainLoopOuterPointer
  // Copy-throw the caught UTF-16 pointer through the native guard's dedicated throw slot.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 1090a177 : UnwindMainLoopOuterFailure
  // Append this guard's context and rethrow the active exception without extra rollback.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_mainLoopGuardName));
    throw;
  }
}

// RavenShield.exe @ 10912580 : DestroyMainLoopRecords
// Destroy the live twelve-byte string array at parent EBP-40 through its canonical destructor.
__declspec(naked) void DestroyMainLoopRecords()
{
  __asm {
    lea ecx, [ebp-40h]
    jmp NativeEntry_TArray_FString_DestroyTArray
  }
}

// RavenShield.exe @ 10912588 : DestroyMainLoopReport
// Destroy the live benchmark report FString at parent EBP-154 during exception unwinding.
__declspec(naked) void DestroyMainLoopReport()
{
  __asm {
    lea ecx, [ebp-154h]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 10912594 : DestroyMainLoopSummary
// Destroy the formatted benchmark summary FString at parent EBP-194 during exception unwinding.
__declspec(naked) void DestroyMainLoopSummary()
{
  __asm {
    lea ecx, [ebp-194h]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe data @ 109196ec : g_mainLoopUnwind
const NativeCppUnwindEntry g_mainLoopUnwind[21] = {
    {-1, 0},
    {0, 0},
    {0, 0},
    {0, NativeAddress(NativeEntry_DestroyMainLoopRecords)}, // DestroyMainLoopRecords
    {3, 0},
    {3, 0},
    {3, 0},
    {3, 0},
    {3, 0},
    {8, 0},
    {8, 0},
    {8, 0},
    {8, 0},
    {3, 0},
    {3, 0},
    {3, 0},
    {3, NativeAddress(NativeEntry_DestroyMainLoopReport)},   // DestroyMainLoopReport
    {16, NativeAddress(NativeEntry_DestroyMainLoopSummary)}, // DestroyMainLoopSummary
    {3, 0},
    {3, 0},
    {-1, 0},
};

// RavenShield.exe data @ 10919794 : g_mainLoopEnterCatches
const NativeCppCatchHandler g_mainLoopEnterCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x58, 0x10909358}, // RethrowMainLoopEnterPointer
    {0, 0, 0, 0x10909372},                                               // UnwindMainLoopEnterFailure
};

// RavenShield.exe data @ 109197b4 : g_mainLoopWorldCatches
const NativeCppCatchHandler g_mainLoopWorldCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x88, 0x10909a65}, // RethrowMainLoopWorldPointer
    {0, 0, 0, 0x10909a82},                                               // UnwindMainLoopWorldFailure
};

// RavenShield.exe data @ 109197d4 : g_mainLoopTickRateCatches
const NativeCppCatchHandler g_mainLoopTickRateCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x94, 0x10909b1d}, // RethrowMainLoopTickRatePointer
    {0, 0, 0, 0x10909b3a},                                               // UnwindMainLoopTickRateFailure
};

// RavenShield.exe data @ 109197f4 : g_mainLoopTranslateCatches
const NativeCppCatchHandler g_mainLoopTranslateCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0xb4, 0x10909bf0}, // RethrowMainLoopTranslatePointer
    {0, 0, 0, 0x10909c0d},                                               // UnwindMainLoopTranslateFailure
};

// RavenShield.exe data @ 10919814 : g_mainLoopDispatchCatches
const NativeCppCatchHandler g_mainLoopDispatchCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0xb8, 0x10909c85}, // RethrowMainLoopDispatchPointer
    {0, 0, 0, 0x10909ca2},                                               // UnwindMainLoopDispatchFailure
};

// RavenShield.exe data @ 10919834 : g_mainLoopMessagePumpCatches
const NativeCppCatchHandler g_mainLoopMessagePumpCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0xbc, 0x10909ce8}, // RethrowMainLoopMessagePumpPointer
    {0, 0, 0, 0x10909d05},                                               // UnwindMainLoopMessagePumpFailure
};

// RavenShield.exe data @ 10919854 : g_mainLoopThrottleCatches
const NativeCppCatchHandler g_mainLoopThrottleCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0xc4, 0x10909db5}, // RethrowMainLoopThrottlePointer
    {0, 0, 0, 0x10909dd2},                                               // UnwindMainLoopThrottleFailure
};

// RavenShield.exe data @ 10919874 : g_mainLoopExitCatches
const NativeCppCatchHandler g_mainLoopExitCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x164, 0x1090a110}, // RethrowMainLoopExitPointer
    {0, 0, 0, 0x1090a12d},                                                // UnwindMainLoopExitFailure
};

// RavenShield.exe data @ 10919894 : g_mainLoopOuterCatches
const NativeCppCatchHandler g_mainLoopOuterCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x168, 0x1090a15a}, // RethrowMainLoopOuterPointer
    {0, 0, 0, 0x1090a177},                                                // UnwindMainLoopOuterFailure
};

// RavenShield.exe data @ 109198b4 : g_mainLoopTryBlocks
const NativeCppTryBlock g_mainLoopTryBlocks[9] = {
    {1, 1, 2, 2, NativeAddress(g_mainLoopEnterCatches)},
    {4, 4, 5, 2, NativeAddress(g_mainLoopWorldCatches)},
    {6, 6, 7, 2, NativeAddress(g_mainLoopTickRateCatches)},
    {9, 9, 10, 2, NativeAddress(g_mainLoopTranslateCatches)},
    {11, 11, 12, 2, NativeAddress(g_mainLoopDispatchCatches)},
    {8, 12, 13, 2, NativeAddress(g_mainLoopMessagePumpCatches)},
    {14, 14, 15, 2, NativeAddress(g_mainLoopThrottleCatches)},
    {18, 18, 19, 2, NativeAddress(g_mainLoopExitCatches)},
    {0, 19, 20, 2, NativeAddress(g_mainLoopOuterCatches)},
};

// RavenShield.exe data @ 10919968 : g_mainLoopExceptionInfo
const NativeCppFunctionInfo g_mainLoopExceptionInfo = {
    0x19930520, 21, NativeAddress(g_mainLoopUnwind), 9, NativeAddress(g_mainLoopTryBlocks), 0, 0};

// RavenShield.exe @ 109125a0 : HandleMainLoopException
// Dispatch the complete twenty-one-state record/report cleanup and nine nested guard scopes.
__declspec(naked) void HandleMainLoopException()
{
  __asm {
    mov eax, offset g_mainLoopExceptionInfo
    jmp DispatchExecutableCppException
  }
}
