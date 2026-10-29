#include "native_symbols.hpp"
// Windows allocator pool lifetime and diagnostics; offsets retain the selected x86 object layout.
#include "cpp_exception_metadata.hpp"
#include "launch_runtime.hpp"
#include "allocation_support.hpp"
#include <new>

// RavenShield.exe data @ 10914c50 : g_windowsAllocatorVtable
// Native x86 virtual-table words retain slot offsets and canonical targets without adding public class fields.
const uint32_t g_windowsAllocatorVtable[10] = {
    NativeAddress(NativeEntry_FMallocWindows_Malloc),            // +000 FMallocWindows::Malloc
    NativeAddress(NativeEntry_FMallocWindows_Realloc),           // +004 FMallocWindows::Realloc
    NativeAddress(NativeEntry_FMallocWindows_Free),              // +008 FMallocWindows::Free
    NativeAddress(NativeEntry_FMallocWindows_DumpAllocs),        // +00c FMallocWindows::DumpAllocs
    NativeAddress(NativeEntry_IgnoreSharedVirtualArgument),      // +010 IgnoreSharedVirtualArgument
    NativeAddress(NativeEntry_FMallocWindows_HeapCheck),         // +014 FMallocWindows::HeapCheck
    NativeAddress(NativeEntry_FMallocWindows_Init),              // +018 FMallocWindows::Init
    NativeAddress(NativeEntry_FMallocWindows_Exit),              // +01c FMallocWindows::Exit
    NativeAddress(NativeEntry_FMallocWindows_FormatMemoryStats), // +020 FMallocWindows::FormatMemoryStats
    NativeAddress(NativeEntry_FMalloc_GetMemoryBlockSize),       // +024 FMalloc::GetMemoryBlockSize
};

// RavenShield.exe data @ 1091f720 : g_launchAllocatorStorage
alignas(4) uint8_t g_launchAllocatorStorage[0x2069c] = {};

// RavenShield.exe @ 10902900 : FMallocWindows::FMallocWindows
// Construct the imported base, install the allocator table and reset bookkeeping, leaving pool tables untouched.
FMallocWindows::FMallocWindows() : FMalloc() // Imported Core.dll base constructor, IAT 1091410c.
{
  auto *object = reinterpret_cast<uint8_t *>(this);
  *reinterpret_cast<const uint32_t **>(object) = g_windowsAllocatorVtable;
  *reinterpret_cast<uint32_t *>(object + 0x20678) = 0; // MemInit.
  *reinterpret_cast<uint32_t *>(object + 0x2067c) = 0; // OsCurrent.
  *reinterpret_cast<uint32_t *>(object + 0x20680) = 0; // OsPeak.
  *reinterpret_cast<uint32_t *>(object + 0x20684) = 0; // UsedCurrent.
  *reinterpret_cast<uint32_t *>(object + 0x20688) = 0; // UsedPeak.
  *reinterpret_cast<uint32_t *>(object + 0x2068c) = 0; // CurrentAllocs.
  *reinterpret_cast<uint32_t *>(object + 0x20690) = 0; // TotalAllocs.
  *reinterpret_cast<double *>(object + 0x20694) = 0.0;
}

// RavenShield.exe @ 10912f80 : InitializeLaunchAllocator
// Construct the static allocator backing later passed to appInit.
void __cdecl InitializeLaunchAllocator()
{
  new (g_launchAllocatorStorage) FMallocWindows;
}

// Fixed-width Win32 SYSTEM_INFO layout; only the page-size word at +4 is consumed by allocator initialization.
struct AllocatorSystemInfoX86
{
  uint32_t processorInformation, pageSize, minimumApplicationAddress, maximumApplicationAddress;
  uint32_t activeProcessorMask, numberOfProcessors, processorType, allocationGranularity;
  uint16_t processorLevel, processorRevision;
};
extern "C" void __stdcall GetSystemInfo(AllocatorSystemInfoX86 *information);
extern "C" void __stdcall InitializeCriticalSection(void *criticalSection);
extern uint32_t GPageSize;
extern void __cdecl appFailAssert(const char *expression, const char *file, int32_t line);
extern void __cdecl appUnwindf(const uint16_t *format, ...);
extern int32_t __cdecl appSprintf(uint16_t *destination, const uint16_t *format, ...);
extern "C" void DispatchExecutableCppException();

// RavenShield.exe data @ 10914c78 : g_allocatorHeapCheckGuardName
const char16_t g_allocatorHeapCheckGuardName[] = u"FMallocWindows::HeapCheck";
// RavenShield.exe data @ 10914d14 : g_allocatorInitGuardName
const char16_t g_allocatorInitGuardName[] = u"FMallocWindows::Init";
// RavenShield.exe data @ 10914cac : g_allocatorExhaustedPoolExpression
const char g_allocatorExhaustedPoolExpression[] = "!Pool->FirstMem";
// RavenShield.exe data @ 10914cbc : g_allocatorFreeBlocksExpression
const char g_allocatorFreeBlocksExpression[] = "Free->Blocks>0";
// RavenShield.exe data @ 10914ccc : g_allocatorFreeHeadExpression
const char g_allocatorFreeHeadExpression[] = "Pool->FirstMem";
// RavenShield.exe data @ 10914cdc : g_allocatorPreviousLinkExpression
const char g_allocatorPreviousLinkExpression[] = "Pool->PrevLink==PoolPtr";
// RavenShield.exe data @ 10914cf4 : g_allocatorSourcePath
const char g_allocatorSourcePath[] = "..\\..\\Core\\Inc\\FMallocWindows.h";
// RavenShield.exe data @ 10914d40 : g_allocatorLargestPoolExpression
const char g_allocatorLargestPoolExpression[] = "POOL_MAX-1==PoolTable[POOL_COUNT-1].BlockSize";
// RavenShield.exe data @ 10914d70 : g_allocatorPageSizeExpression
const char g_allocatorPageSizeExpression[] = "!(GPageSize&(GPageSize-1))";
// RavenShield.exe data @ 10914d8c : g_allocatorUninitializedExpression
const char g_allocatorUninitializedExpression[] = "!MemInit";
// RavenShield.exe data @ 10914d98 : g_allocatorAllocationStatsFormat
const char16_t g_allocatorAllocationStatsFormat[] = u"%s,  Allocs: %i Current / %i Total";
// RavenShield.exe data @ 10914de0 : g_allocatorPeakStatsFormat
const char16_t g_allocatorPeakStatsFormat[] = u"%s,  Peak Memory: %.3fM / %.3fM";
// RavenShield.exe data @ 10914e20 : g_allocatorCurrentStatsFormat
const char16_t g_allocatorCurrentStatsFormat[] = u"Curr Memory: %.3fM / %.3fM";
// RavenShield.exe data @ 10914e58 : g_allocatorStatsDivisor
const double g_allocatorStatsDivisor = 1024.0;

// RavenShield.exe @ 109029b0 : FMallocWindows::HeapCheck
// Check both lists in all 49 pool tables, retaining native assertion continuation and post-callback link reloads.
void FMallocWindows::HeapCheck()
{
  try
  {
    auto *object = reinterpret_cast<uint8_t *>(this);
    for (int32_t table = 0; table < 49; ++table)
    {
      const uint32_t tableAddress = reinterpret_cast<uint32_t>(object + 0x1c + table * 0xc);
      uint32_t link = tableAddress;
      while (*reinterpret_cast<const uint32_t *>(link) != 0)
      {
        const uint32_t pool = *reinterpret_cast<const uint32_t *>(link);
        if (*reinterpret_cast<const uint32_t *>(pool + 0x1c) != link)
          appFailAssert(g_allocatorPreviousLinkExpression, g_allocatorSourcePath, 0x18c);
        if (*reinterpret_cast<const uint32_t *>(pool + 0x14) == 0)
          appFailAssert(g_allocatorFreeHeadExpression, g_allocatorSourcePath, 0x18d);
        uint32_t freeBlock = *reinterpret_cast<const uint32_t *>(pool + 0x14);
        while (freeBlock != 0)
        {
          if (*reinterpret_cast<const uint32_t *>(freeBlock + 4) == 0) // Native unsigned >0 admits every nonzero word.
            appFailAssert(g_allocatorFreeBlocksExpression, g_allocatorSourcePath, 0x18f);
          freeBlock = *reinterpret_cast<const uint32_t *>(freeBlock);
        }
        link = *reinterpret_cast<const uint32_t *>(link) + 0x18; // Reload the link slot, not the saved pool pointer.
      }
      link = tableAddress + 4;
      while (*reinterpret_cast<const uint32_t *>(link) != 0)
      {
        const uint32_t pool = *reinterpret_cast<const uint32_t *>(link);
        if (*reinterpret_cast<const uint32_t *>(pool + 0x1c) != link)
          appFailAssert(g_allocatorPreviousLinkExpression, g_allocatorSourcePath, 0x194);
        if (*reinterpret_cast<const uint32_t *>(pool + 0x14) != 0)
          appFailAssert(g_allocatorExhaustedPoolExpression, g_allocatorSourcePath, 0x195);
        link = *reinterpret_cast<const uint32_t *>(link) + 0x18;
      }
    }
  }
  // RavenShield.exe @ 10902b45 : RethrowAllocatorHeapCheckPointer
  // Copy-throw the caught pointer from parent EBP-30 into a new throw object at EBP-34.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 10902b59 : UnwindAllocatorHeapCheckFailure
  // Append the native HeapCheck guard and rethrow the active exception.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_allocatorHeapCheckGuardName));
    throw;
  }
}

// RavenShield.exe data @ 1091873c : g_allocatorHeapCheckUnwind
const NativeCppUnwindEntry g_allocatorHeapCheckUnwind[2] = {
    {-1, 0},
    {-1, 0},
};

// RavenShield.exe data @ 1091874c : g_allocatorHeapCheckCatches
const NativeCppCatchHandler g_allocatorHeapCheckCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x30, 0x10902b45}, // RethrowAllocatorHeapCheckPointer
    {0, 0, 0, 0x10902b59},                                               // UnwindAllocatorHeapCheckFailure
};

// RavenShield.exe data @ 1091876c : g_allocatorHeapCheckTryBlocks
const NativeCppTryBlock g_allocatorHeapCheckTryBlocks[1] = {
    {0, 0, 1, 2, NativeAddress(g_allocatorHeapCheckCatches)},
};

// RavenShield.exe data @ 10918780 : g_allocatorHeapCheckExceptionInfo
const NativeCppFunctionInfo g_allocatorHeapCheckExceptionInfo = {
    0x19930520, 2, NativeAddress(g_allocatorHeapCheckUnwind), 1, NativeAddress(g_allocatorHeapCheckTryBlocks), 0, 0};

// RavenShield.exe @ 109121b0 : HandleAllocatorHeapCheckException
// Supply HeapCheck's two-state typed-pointer/catch-all guard map with no cleanup actions.
__declspec(naked) void HandleAllocatorHeapCheckException()
{
  __asm {
    mov eax, offset g_allocatorHeapCheckExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// RavenShield.exe @ 10902b90 : FMallocWindows::Init
// Mark initialized, obtain page size, build pool lookup tables and initialize the critical section last.
void FMallocWindows::Init()
{
  try
  {
    auto *object = reinterpret_cast<uint8_t *>(this);
    if (*reinterpret_cast<const int32_t *>(object + 0x20678) != 0)
      appFailAssert(g_allocatorUninitializedExpression, g_allocatorSourcePath, 0x19d);
    *reinterpret_cast<int32_t *>(object + 0x20678) = 1;
    AllocatorSystemInfoX86 information;
    GetSystemInfo(&information);
    GPageSize = information.pageSize;
    const uint32_t pageMinusOne = GPageSize - 1;
    if ((pageMinusOne & GPageSize) != 0) appFailAssert(g_allocatorPageSizeExpression, g_allocatorSourcePath, 0x1a7);
    *reinterpret_cast<uint32_t *>(object + 0x268) = 0;
    *reinterpret_cast<uint32_t *>(object + 0x26c) = 0;
    *reinterpret_cast<uint32_t *>(object + 0x270) = 0;
    for (uint32_t index = 0; index < 49; ++index)
    {
      *reinterpret_cast<uint32_t *>(object + 0x1c + index * 0xc) = 0;
      *reinterpret_cast<uint32_t *>(object + 0x20 + index * 0xc) = 0;
      const uint32_t shift = ((index >> 2) + 1) & 0x1f;
      *reinterpret_cast<uint32_t *>(object + 0x24 + index * 0xc) = (4 + (index & 3)) << shift;
    }
    for (uint32_t size = 0; size < 0x8001; ++size)
    {
      uint32_t index = 0;
      while (*reinterpret_cast<const uint32_t *>(object + 0x24 + index * 0xc) < size) ++index;
      *reinterpret_cast<uint32_t *>(object + 0x674 + size * 4) =
          reinterpret_cast<uint32_t>(object + 0x1c + index * 0xc);
    }
    for (uint32_t index = 0; index < 256; ++index) *reinterpret_cast<uint32_t *>(object + 0x274 + index * 4) = 0;
    if (*reinterpret_cast<const uint32_t *>(object + 0x264) != 0x8000)
      appFailAssert(g_allocatorLargestPoolExpression, g_allocatorSourcePath, 0x1be);
    InitializeCriticalSection(object + 4);
  }
  // RavenShield.exe @ 10902d8b : RethrowAllocatorInitPointer
  // Copy-throw the caught pointer from parent EBP-48 into a new throw object at EBP-4c.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 10902d9f : UnwindAllocatorInitFailure
  // Append Init's guard and rethrow without rolling back MemInit, table writes or page size.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_allocatorInitGuardName));
    throw;
  }
}

// RavenShield.exe data @ 1091879c : g_allocatorInitUnwind
const NativeCppUnwindEntry g_allocatorInitUnwind[2] = {
    {-1, 0},
    {-1, 0},
};

// RavenShield.exe data @ 109187ac : g_allocatorInitCatches
const NativeCppCatchHandler g_allocatorInitCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x48, 0x10902d8b}, // RethrowAllocatorInitPointer
    {0, 0, 0, 0x10902d9f},                                               // UnwindAllocatorInitFailure
};

// RavenShield.exe data @ 109187cc : g_allocatorInitTryBlocks
const NativeCppTryBlock g_allocatorInitTryBlocks[1] = {
    {0, 0, 1, 2, NativeAddress(g_allocatorInitCatches)},
};

// RavenShield.exe data @ 109187e0 : g_allocatorInitExceptionInfo
const NativeCppFunctionInfo g_allocatorInitExceptionInfo = {
    0x19930520, 2, NativeAddress(g_allocatorInitUnwind), 1, NativeAddress(g_allocatorInitTryBlocks), 0, 0};

// RavenShield.exe @ 109121c0 : HandleAllocatorInitException
// Supply Init's two-state typed-pointer/catch-all guard map with no cleanup actions.
__declspec(naked) void HandleAllocatorInitException()
{
  __asm {
    mov eax, offset g_allocatorInitExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// RavenShield.exe @ 10902de0 : FMallocWindows::Exit
// Leave allocator state unchanged, including MemInit and the critical section; the native method is a genuine no-op.
void FMallocWindows::Exit() {}

// RavenShield.exe @ 10902df0 : FMallocWindows::FormatMemoryStats
// Format signed current/peak counters in MiB and allocation counts in place; preserve the last formatter's EAX word.
int32_t FMallocWindows::FormatMemoryStats(uint16_t *output)
{
  const auto *object = reinterpret_cast<const uint8_t *>(this);
  const double currentOs =
      (static_cast<double>(*reinterpret_cast<const int32_t *>(object + 0x2067c)) / g_allocatorStatsDivisor) /
      g_allocatorStatsDivisor;
  const double currentUsed =
      (static_cast<double>(*reinterpret_cast<const int32_t *>(object + 0x20684)) / g_allocatorStatsDivisor) /
      g_allocatorStatsDivisor;
  appSprintf(output, reinterpret_cast<const uint16_t *>(g_allocatorCurrentStatsFormat), currentUsed, currentOs);
  const double peakOs =
      (static_cast<double>(*reinterpret_cast<const int32_t *>(object + 0x20680)) / g_allocatorStatsDivisor) /
      g_allocatorStatsDivisor;
  const double peakUsed =
      (static_cast<double>(*reinterpret_cast<const int32_t *>(object + 0x20688)) / g_allocatorStatsDivisor) /
      g_allocatorStatsDivisor;
  appSprintf(output, reinterpret_cast<const uint16_t *>(g_allocatorPeakStatsFormat), output, peakUsed, peakOs);
  const int32_t total = *reinterpret_cast<const int32_t *>(object + 0x20690);
  const int32_t current = *reinterpret_cast<const int32_t *>(object + 0x2068c);
  return appSprintf(output, reinterpret_cast<const uint16_t *>(g_allocatorAllocationStatsFormat), output, current,
                    total);
}

class FOutputDevice;
extern FOutputDevice *GLog;
using AllocatorLogf = void(__cdecl *)(FOutputDevice *, const uint16_t *, ...);
extern const uint16_t *__cdecl appCmdLine();
extern int32_t __cdecl ParseParam(const uint16_t *commandLine, const uint16_t *parameter);

// RavenShield.exe data @ 10915550 : g_allocatorDumpGuardName
const char16_t g_allocatorDumpGuardName[] = u"FMallocWindows::DumpAllocs";
// RavenShield.exe data @ 10915588 : g_allocatorOverallFormat
const char16_t g_allocatorOverallFormat[] = u"BlkOverall % 9i % 10i % 11iK % 7iK % 8iK % 9.2f%%";
// RavenShield.exe data @ 109155f0 : g_allocatorPoolFormat
const char16_t g_allocatorPoolFormat[] = u"% 10i % 9i % 10i % 11iK % 7iK % 8iK % 9.2f%%";
// RavenShield.exe data @ 10915650 : g_allocatorPercentScale
const double g_allocatorPercentScale = 100.0;
// RavenShield.exe data @ 10915658 : g_allocatorPoolSeparator
const char16_t g_allocatorPoolSeparator[] =
    u"---------- --------- ---------- ------------ -------- --------- ----------";
// RavenShield.exe data @ 109156f0 : g_allocatorPoolHeading
const char16_t g_allocatorPoolHeading[] = u"Block Size Num Pools Cur Allocs Total Allocs Mem Used Mem Waste Efficiency";
// RavenShield.exe data @ 10915788 : g_allocatorMemstatParameter
const char16_t g_allocatorMemstatParameter[] = u"MEMSTAT";
// RavenShield.exe data @ 10915798 : g_allocatorDumpAllocationsFormat
const char16_t g_allocatorDumpAllocationsFormat[] = u"Allocs      % 6i Current / % 6i Total";
// RavenShield.exe data @ 109157e4 : g_allocatorDumpPeakFormat
const char16_t g_allocatorDumpPeakFormat[] = u"Peak Memory % 5.3fM / % 5.3fM";
// RavenShield.exe data @ 10915820 : g_allocatorDumpCurrentFormat
const char16_t g_allocatorDumpCurrentFormat[] = u"Curr Memory % 5.3fM / % 5.3fM";
// RavenShield.exe data @ 1091585c : g_allocatorDumpHeading
const char16_t g_allocatorDumpHeading[] = u"Memory Allocation Status";

// RavenShield.exe @ 10905200 : FMallocWindows::DumpAllocs
// Check the heap and log counters; MEMSTAT adds both pool lists, discarded free counts and wrapped pool totals.
void FMallocWindows::DumpAllocs()
{
  try
  {
    FMallocWindows::HeapCheck(); // Native direct call, independent of the current virtual table.
    const auto &logf = *reinterpret_cast<const AllocatorLogf *>(NativeAddress(NativeImport_FOutputDeviceLogf));
    auto *object = reinterpret_cast<uint8_t *>(this);
    logf(GLog, reinterpret_cast<const uint16_t *>(g_allocatorDumpHeading));
    const double currentOs =
        (static_cast<double>(*reinterpret_cast<const int32_t *>(object + 0x2067c)) / g_allocatorStatsDivisor) /
        g_allocatorStatsDivisor;
    const double currentUsed =
        (static_cast<double>(*reinterpret_cast<const int32_t *>(object + 0x20684)) / g_allocatorStatsDivisor) /
        g_allocatorStatsDivisor;
    logf(GLog, reinterpret_cast<const uint16_t *>(g_allocatorDumpCurrentFormat), currentUsed, currentOs);
    const double peakOs =
        (static_cast<double>(*reinterpret_cast<const int32_t *>(object + 0x20680)) / g_allocatorStatsDivisor) /
        g_allocatorStatsDivisor;
    const double peakUsed =
        (static_cast<double>(*reinterpret_cast<const int32_t *>(object + 0x20688)) / g_allocatorStatsDivisor) /
        g_allocatorStatsDivisor;
    logf(GLog, reinterpret_cast<const uint16_t *>(g_allocatorDumpPeakFormat), peakUsed, peakOs);
    const int32_t totalAllocs = *reinterpret_cast<const int32_t *>(object + 0x20690);
    const int32_t currentAllocs = *reinterpret_cast<const int32_t *>(object + 0x2068c);
    logf(GLog, reinterpret_cast<const uint16_t *>(g_allocatorDumpAllocationsFormat), currentAllocs, totalAllocs);
    const uint16_t *commandLine = appCmdLine();
    if (ParseParam(commandLine, reinterpret_cast<const uint16_t *>(g_allocatorMemstatParameter)) != 0)
    {
      logf(GLog, reinterpret_cast<const uint16_t *>(g_allocatorPoolHeading));
      logf(GLog, reinterpret_cast<const uint16_t *>(g_allocatorPoolSeparator));
      uint32_t totalPools = 0, totalTaken = 0, totalBytes = 0, totalWaste = 0;
      for (int32_t index = 0; index < 49; ++index)
      {
        auto *table = object + 0x1c + index * 0xc;
        uint32_t pools = 0, taken = 0, bytes = 0;
        for (int32_t list = 0; list < 2; ++list)
        {
          uint32_t pool = *reinterpret_cast<const uint32_t *>(table + (list != 0 ? 0 : 4));
          while (pool != 0)
          {
            ++pools;
            taken += *reinterpret_cast<const uint32_t *>(pool + 8);
            bytes += *reinterpret_cast<const uint32_t *>(pool);
            uint32_t freeCount = 0;
            uint32_t freeBlock = *reinterpret_cast<const uint32_t *>(pool + 0x14);
            while (freeBlock != 0)
            {
              freeCount += *reinterpret_cast<const uint32_t *>(freeBlock + 4); // Traversed even though unused.
              freeBlock = *reinterpret_cast<const uint32_t *>(freeBlock);
            }
            pool = *reinterpret_cast<const uint32_t *>(pool + 0x18);
          }
        }
        const uint32_t waste = bytes - taken * *reinterpret_cast<const uint32_t *>(table + 8);
        const int32_t denominator = static_cast<int32_t>(bytes + waste);
        const double efficiency =
            bytes != 0 ? g_allocatorPercentScale * static_cast<int32_t>(bytes) / denominator : g_allocatorPercentScale;
        const int32_t wasteKiB = static_cast<int32_t>(waste) / 1024;
        const int32_t usedKiB = static_cast<int32_t>(bytes) / 1024;
        const int32_t blockSize = *reinterpret_cast<const int32_t *>(table + 8);
        logf(GLog, reinterpret_cast<const uint16_t *>(g_allocatorPoolFormat), blockSize, static_cast<int32_t>(pools),
             static_cast<int32_t>(taken), 0, usedKiB, wasteKiB, efficiency);
        totalPools += pools;
        totalTaken += taken;
        totalBytes += bytes;
        totalWaste += waste;
      }
      const int32_t denominator = static_cast<int32_t>(totalBytes + totalWaste);
      const double efficiency = totalBytes != 0
                                    ? g_allocatorPercentScale * static_cast<int32_t>(totalBytes) / denominator
                                    : g_allocatorPercentScale;
      const int32_t wasteKiB = static_cast<int32_t>(totalWaste) / 1024;
      const int32_t usedKiB = static_cast<int32_t>(totalBytes) / 1024;
      logf(GLog, reinterpret_cast<const uint16_t *>(g_allocatorOverallFormat), static_cast<int32_t>(totalPools),
           static_cast<int32_t>(totalTaken), 0, usedKiB, wasteKiB, efficiency);
    }
  }
  // RavenShield.exe @ 109055b2 : RethrowAllocatorDumpPointer
  // Copy-throw the caught pointer from parent EBP-4c into a new throw object at EBP-50.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 109055c6 : UnwindAllocatorDumpFailure
  // Append the DumpAllocs guard and rethrow without releasing or mutating allocator state.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_allocatorDumpGuardName));
    throw;
  }
}

// RavenShield.exe data @ 10918e74 : g_allocatorDumpUnwind
const NativeCppUnwindEntry g_allocatorDumpUnwind[2] = {
    {-1, 0},
    {-1, 0},
};

// RavenShield.exe data @ 10918e84 : g_allocatorDumpCatches
const NativeCppCatchHandler g_allocatorDumpCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x4c, 0x109055b2}, // RethrowAllocatorDumpPointer
    {0, 0, 0, 0x109055c6},                                               // UnwindAllocatorDumpFailure
};

// RavenShield.exe data @ 10918ea4 : g_allocatorDumpTryBlocks
const NativeCppTryBlock g_allocatorDumpTryBlocks[1] = {
    {0, 0, 1, 2, NativeAddress(g_allocatorDumpCatches)},
};

// RavenShield.exe data @ 10918eb8 : g_allocatorDumpExceptionInfo
const NativeCppFunctionInfo g_allocatorDumpExceptionInfo = {
    0x19930520, 2, NativeAddress(g_allocatorDumpUnwind), 1, NativeAddress(g_allocatorDumpTryBlocks), 0, 0};

// RavenShield.exe @ 10912360 : HandleAllocatorDumpException
// Supply DumpAllocs's two-state pointer/catch-all guard map; no local objects need cleanup.
__declspec(naked) void HandleAllocatorDumpException()
{
  __asm {
    mov eax, offset g_allocatorDumpExceptionInfo
    jmp DispatchExecutableCppException
  }
}

extern "C" void __stdcall EnterCriticalSection(void *criticalSection);
extern "C" void __stdcall LeaveCriticalSection(void *criticalSection);
extern "C" int32_t __stdcall VirtualFree(void *address, uint32_t size, uint32_t freeType);

// RavenShield.exe data @ 109154d0 : g_allocatorFreeGuardName
const char16_t g_allocatorFreeGuardName[] = u"FMallocWindows::Free";
// RavenShield.exe data @ 109154fc : g_allocatorFreeDirectExpression
const char g_allocatorFreeDirectExpression[] = "VirtualFree( Ptr, 0, MEM_RELEASE )!=0";
// RavenShield.exe data @ 10915524 : g_allocatorFreePoolExpression
const char g_allocatorFreePoolExpression[] = "VirtualFree( Pool->Mem, 0, MEM_RELEASE )!=0";

// RavenShield.exe @ 10904ff0 : FMallocWindows::Free
// Return a block to its pool or release an OS allocation, preserving counter order and explicit normal-path locking.
void FMallocWindows::Free(void *allocation)
{
  try
  {
    if (allocation == nullptr) return;
    using PoolNode = TDoubleLinkedList<FMallocWindows::FPoolInfoBase>;
    auto *object = reinterpret_cast<uint8_t *>(this);
    --*reinterpret_cast<uint32_t *>(object + 0x2068c); // Native decrement precedes lock acquisition.
    EnterCriticalSection(object + 4);
    const uint32_t address = reinterpret_cast<uint32_t>(allocation);
    const uint32_t indirect = *reinterpret_cast<const uint32_t *>(object + 0x274 + (address >> 24) * 4);
    auto *pool = reinterpret_cast<uint8_t *>(indirect + ((address >> 16) & 0xff) * 0x20);
    if (*reinterpret_cast<const uint32_t *>(pool + 0x10) != reinterpret_cast<uint32_t>(object + 0x268))
    {
      if (*reinterpret_cast<const uint32_t *>(pool + 0x14) == 0)
      {
        reinterpret_cast<PoolNode *>(pool)->Unlink();
        const uint32_t table = *reinterpret_cast<const uint32_t *>(pool + 0x10);
        reinterpret_cast<PoolNode *>(pool)->Link(*reinterpret_cast<PoolNode **>(table));
      }
      *reinterpret_cast<uint32_t *>(address + 4) = 1;
      *reinterpret_cast<uint32_t *>(address) = *reinterpret_cast<const uint32_t *>(pool + 0x14);
      *reinterpret_cast<uint32_t *>(pool + 0x14) = address;
      const uint32_t table = *reinterpret_cast<const uint32_t *>(pool + 0x10);
      *reinterpret_cast<uint32_t *>(object + 0x20684) -= *reinterpret_cast<const uint32_t *>(table + 8);
      --*reinterpret_cast<uint32_t *>(pool + 8);
      if (*reinterpret_cast<const uint32_t *>(pool + 8) == 0)
      {
        reinterpret_cast<PoolNode *>(pool)->Unlink();
        void *memory = reinterpret_cast<void *>(*reinterpret_cast<const uint32_t *>(pool + 0xc));
        if (VirtualFree(memory, 0, 0x8000) == 0)
          appFailAssert(g_allocatorFreePoolExpression, g_allocatorSourcePath, 0x126);
        *reinterpret_cast<uint32_t *>(object + 0x2067c) -= *reinterpret_cast<const uint32_t *>(pool + 4);
      }
    }
    else
    {
      *reinterpret_cast<uint32_t *>(object + 0x20684) -= *reinterpret_cast<const uint32_t *>(pool);
      *reinterpret_cast<uint32_t *>(object + 0x2067c) -= *reinterpret_cast<const uint32_t *>(pool + 4);
      if (VirtualFree(allocation, 0, 0x8000) == 0)
        appFailAssert(g_allocatorFreeDirectExpression, g_allocatorSourcePath, 0x130);
    }
    LeaveCriticalSection(object + 4); // Native exceptional paths retain the lock and earlier state changes.
  }
  // RavenShield.exe @ 109051b4 : RethrowAllocatorFreePointer
  // Copy-throw the caught pointer from parent EBP-1c into a new throw object at EBP-20.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 109051c8 : UnwindAllocatorFreeFailure
  // Append the Free guard and rethrow; there is no critical-section cleanup or counter rollback.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_allocatorFreeGuardName));
    throw;
  }
}

// RavenShield.exe data @ 10918e14 : g_allocatorFreeUnwind
const NativeCppUnwindEntry g_allocatorFreeUnwind[2] = {
    {-1, 0},
    {-1, 0},
};

// RavenShield.exe data @ 10918e24 : g_allocatorFreeCatches
const NativeCppCatchHandler g_allocatorFreeCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x1c, 0x109051b4}, // RethrowAllocatorFreePointer
    {0, 0, 0, 0x109051c8},                                               // UnwindAllocatorFreeFailure
};

// RavenShield.exe data @ 10918e44 : g_allocatorFreeTryBlocks
const NativeCppTryBlock g_allocatorFreeTryBlocks[1] = {
    {0, 0, 1, 2, NativeAddress(g_allocatorFreeCatches)},
};

// RavenShield.exe data @ 10918e58 : g_allocatorFreeExceptionInfo
const NativeCppFunctionInfo g_allocatorFreeExceptionInfo = {
    0x19930520, 2, NativeAddress(g_allocatorFreeUnwind), 1, NativeAddress(g_allocatorFreeTryBlocks), 0, 0};

// RavenShield.exe @ 10912350 : HandleAllocatorFreeException
// Supply Free's two-state pointer/catch-all guard map with no lock-release unwind action.
__declspec(naked) void HandleAllocatorFreeException()
{
  __asm {
    mov eax, offset g_allocatorFreeExceptionInfo
    jmp DispatchExecutableCppException
  }
}

class FOutputDeviceError;
extern FOutputDeviceError *GError;
extern const uint16_t *__cdecl LocalizeError(const char *key, const uint16_t *package, const uint16_t *language);
extern "C" void *__stdcall VirtualAlloc(void *address, uint32_t size, uint32_t allocationType, uint32_t protection);

// RavenShield.exe data @ 109147d8 : g_allocatorErrorPackage
extern const char16_t g_allocatorErrorPackage[] = u"R6Engine";
// RavenShield.exe data @ 10915440 : g_allocatorMallocGuardName
const char16_t g_allocatorMallocGuardName[] = u"FMallocWindows::Malloc";
// RavenShield.exe data @ 10915470 : g_allocatorOutOfMemoryKey
const char g_allocatorOutOfMemoryKey[] = "OutOfMemory";
// RavenShield.exe data @ 1091547c : g_allocatorReallocContextFormat
const char16_t g_allocatorReallocContextFormat[] = u"%08X %i %s";
// RavenShield.exe data @ 10915494 : g_allocatorReallocGuardName
const char16_t g_allocatorReallocGuardName[] = u"FMallocWindows::Realloc";
// RavenShield.exe data @ 109154c4 : g_allocatorReallocSizeExpression
const char g_allocatorReallocSizeExpression[] = "NewSize>=0"; // Native unsigned comparison cannot fail.

// RavenShield.exe @ 10904a90 : FMallocWindows::CreateIndirect
// Allocate 256 zero-filled pool descriptors; log a localized error on failure, retaining the original null result.
void *FMallocWindows::CreateIndirect()
{
  void *indirect = VirtualAlloc(nullptr, 0x2000, 0x1000, 4);
  if (indirect == nullptr)
  {
    const uint16_t *error =
        LocalizeError(g_allocatorOutOfMemoryKey, reinterpret_cast<const uint16_t *>(g_allocatorErrorPackage), nullptr);
    FOutputDevice *output = reinterpret_cast<FOutputDevice *>(GError);
    const auto logf = *reinterpret_cast<const AllocatorLogf *>(NativeAddress(NativeImport_FOutputDeviceLogf));
    logf(output, error);
  }
  return indirect;
}

// RavenShield.exe @ 10904630 : FMallocWindows::Malloc
// Allocate from a size-class free chain or the OS, preserving wrapped accounting and normal-path lock release.
void *FMallocWindows::Malloc(uint32_t size, const uint16_t *tag)
{
  try
  {
    using PoolNode = TDoubleLinkedList<FMallocWindows::FPoolInfoBase>;
    auto *object = reinterpret_cast<uint8_t *>(this);
    ++*reinterpret_cast<uint32_t *>(object + 0x2068c);
    ++*reinterpret_cast<uint32_t *>(object + 0x20690);
    EnterCriticalSection(object + 4);
    uint32_t allocation;
    if (size < 0x8001)
    {
      const uint32_t table = *reinterpret_cast<const uint32_t *>(object + 0x674 + size * 4);
      uint32_t pool = *reinterpret_cast<const uint32_t *>(table);
      if (pool == 0)
      {
        const uint32_t blocks = 0x10000 / *reinterpret_cast<const uint32_t *>(table + 8);
        const uint32_t bytes = blocks * *reinterpret_cast<const uint32_t *>(table + 8);
        allocation = reinterpret_cast<uint32_t>(VirtualAlloc(nullptr, bytes, 0x1000, 4));
        if (allocation == 0)
        {
          const uint16_t *error = LocalizeError(g_allocatorOutOfMemoryKey,
                                                reinterpret_cast<const uint16_t *>(g_allocatorErrorPackage), nullptr);
          FOutputDevice *output = reinterpret_cast<FOutputDevice *>(GError);
          const auto logf = *reinterpret_cast<const AllocatorLogf *>(NativeAddress(NativeImport_FOutputDeviceLogf));
          logf(output, error); // A returning logger does not abort native pool initialization.
        }
        auto *indirectSlot = reinterpret_cast<uint32_t *>(object + 0x274 + (allocation >> 24) * 4);
        if (*indirectSlot == 0) *indirectSlot = reinterpret_cast<uint32_t>(CreateIndirect());
        pool = *indirectSlot + ((allocation >> 16) & 0xff) * 0x20;
        reinterpret_cast<PoolNode *>(pool)->Link(*reinterpret_cast<PoolNode **>(table));
        *reinterpret_cast<uint32_t *>(pool + 0xc) = allocation;
        *reinterpret_cast<uint32_t *>(pool) = bytes;
        *reinterpret_cast<uint32_t *>(pool + 4) = Align(bytes, GPageSize);
        *reinterpret_cast<uint32_t *>(object + 0x2067c) += *reinterpret_cast<const uint32_t *>(pool + 4);
        const int32_t currentOs = *reinterpret_cast<const int32_t *>(object + 0x2067c);
        const int32_t peakOs = *reinterpret_cast<const int32_t *>(object + 0x20680);
        *reinterpret_cast<int32_t *>(object + 0x20680) = MaxSigned(peakOs, currentOs);
        *reinterpret_cast<uint32_t *>(pool + 0x10) = table;
        *reinterpret_cast<uint32_t *>(pool + 8) = 0;
        *reinterpret_cast<uint32_t *>(pool + 0x14) = allocation;
        *reinterpret_cast<uint32_t *>(allocation + 4) = blocks;
        *reinterpret_cast<uint32_t *>(allocation) = 0;
      }
      ++*reinterpret_cast<uint32_t *>(pool + 8);
      const uint32_t firstFree = *reinterpret_cast<const uint32_t *>(pool + 0x14);
      const uint32_t freeForCount = *reinterpret_cast<const uint32_t *>(pool + 0x14);
      *reinterpret_cast<uint32_t *>(firstFree + 4) = *reinterpret_cast<const uint32_t *>(freeForCount + 4) - 1;
      const uint32_t freeForOffset = *reinterpret_cast<const uint32_t *>(pool + 0x14);
      const uint32_t offset =
          *reinterpret_cast<const uint32_t *>(freeForOffset + 4) * *reinterpret_cast<const uint32_t *>(table + 8);
      allocation = *reinterpret_cast<const uint32_t *>(pool + 0x14) + offset;
      const uint32_t freeForTest = *reinterpret_cast<const uint32_t *>(pool + 0x14);
      if (*reinterpret_cast<const uint32_t *>(freeForTest + 4) == 0)
      {
        const uint32_t freeForNext = *reinterpret_cast<const uint32_t *>(pool + 0x14);
        *reinterpret_cast<uint32_t *>(pool + 0x14) = *reinterpret_cast<const uint32_t *>(freeForNext);
        if (*reinterpret_cast<const uint32_t *>(pool + 0x14) == 0)
        {
          reinterpret_cast<PoolNode *>(pool)->Unlink();
          reinterpret_cast<PoolNode *>(pool)->Link(*reinterpret_cast<PoolNode **>(table + 4));
        }
      }
      *reinterpret_cast<uint32_t *>(object + 0x20684) += *reinterpret_cast<const uint32_t *>(table + 8);
      const int32_t currentUsed = *reinterpret_cast<const int32_t *>(object + 0x20684);
      const int32_t peakUsed = *reinterpret_cast<const int32_t *>(object + 0x20688);
      *reinterpret_cast<int32_t *>(object + 0x20688) = MaxSigned(peakUsed, currentUsed);
    }
    else
    {
      const uint32_t alignedSize = Align(size, GPageSize);
      allocation = reinterpret_cast<uint32_t>(VirtualAlloc(nullptr, alignedSize, 0x1000, 4));
      if (allocation == 0)
      {
        const uint16_t *error = LocalizeError(g_allocatorOutOfMemoryKey,
                                              reinterpret_cast<const uint16_t *>(g_allocatorErrorPackage), nullptr);
        FOutputDevice *output = reinterpret_cast<FOutputDevice *>(GError);
        const auto logf = *reinterpret_cast<const AllocatorLogf *>(NativeAddress(NativeImport_FOutputDeviceLogf));
        logf(output, error);
      }
      auto *indirectSlot = reinterpret_cast<uint32_t *>(object + 0x274 + (allocation >> 24) * 4);
      if (*indirectSlot == 0) *indirectSlot = reinterpret_cast<uint32_t>(CreateIndirect());
      const uint32_t pool = *indirectSlot + ((allocation >> 16) & 0xff) * 0x20;
      *reinterpret_cast<uint32_t *>(pool + 0xc) = allocation;
      *reinterpret_cast<uint32_t *>(pool) = size;
      *reinterpret_cast<uint32_t *>(pool + 4) = alignedSize;
      *reinterpret_cast<uint32_t *>(pool + 0x10) = reinterpret_cast<uint32_t>(object + 0x268);
      *reinterpret_cast<uint32_t *>(object + 0x2067c) += alignedSize;
      const int32_t currentOs = *reinterpret_cast<const int32_t *>(object + 0x2067c);
      const int32_t peakOs = *reinterpret_cast<const int32_t *>(object + 0x20680);
      *reinterpret_cast<int32_t *>(object + 0x20680) = MaxSigned(peakOs, currentOs);
      *reinterpret_cast<uint32_t *>(object + 0x20684) += size;
      const int32_t currentUsed = *reinterpret_cast<const int32_t *>(object + 0x20684);
      const int32_t peakUsed = *reinterpret_cast<const int32_t *>(object + 0x20688);
      *reinterpret_cast<int32_t *>(object + 0x20688) = MaxSigned(peakUsed, currentUsed);
    }
    LeaveCriticalSection(object + 4);
    return reinterpret_cast<void *>(allocation); // Native ignores tag, including when size is zero.
  }
  // RavenShield.exe @ 10904a41 : RethrowAllocatorMallocPointer
  // Copy-throw the caught pointer from parent EBP-38 into a new throw object at EBP-3c.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 10904a55 : UnwindAllocatorMallocFailure
  // Append the Malloc guard and rethrow without unlocking, rolling back counters or releasing allocated storage.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_allocatorMallocGuardName));
    throw;
  }
}

// RavenShield.exe data @ 10918d54 : g_allocatorMallocUnwind
const NativeCppUnwindEntry g_allocatorMallocUnwind[2] = {
    {-1, 0},
    {-1, 0},
};

// RavenShield.exe data @ 10918d64 : g_allocatorMallocCatches
const NativeCppCatchHandler g_allocatorMallocCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x38, 0x10904a41}, // RethrowAllocatorMallocPointer
    {0, 0, 0, 0x10904a55},                                               // UnwindAllocatorMallocFailure
};

// RavenShield.exe data @ 10918d84 : g_allocatorMallocTryBlocks
const NativeCppTryBlock g_allocatorMallocTryBlocks[1] = {
    {0, 0, 1, 2, NativeAddress(g_allocatorMallocCatches)},
};

// RavenShield.exe data @ 10918d98 : g_allocatorMallocExceptionInfo
const NativeCppFunctionInfo g_allocatorMallocExceptionInfo = {
    0x19930520, 2, NativeAddress(g_allocatorMallocUnwind), 1, NativeAddress(g_allocatorMallocTryBlocks), 0, 0};

// RavenShield.exe @ 10912330 : HandleAllocatorMallocException
// Supply Malloc's two-state pointer/catch-all guard map with no cleanup actions.
__declspec(naked) void HandleAllocatorMallocException()
{
  __asm {
    mov eax, offset g_allocatorMallocExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// RavenShield.exe @ 10904ba0 : FMallocWindows::Realloc
// Retain a matching block or virtually allocate, copy and free; in-place OS resizing changes only descriptor Bytes.
void *FMallocWindows::Realloc(void *allocation, uint32_t newSize, const uint16_t *tag)
{
  try
  {
    // Source-only dispatch helpers reload this receiver's table at each native call site, including after copying.
    const auto allocate = [this](uint32_t size, const uint16_t *allocationTag)
    {
      const uint32_t table = *reinterpret_cast<const uint32_t *>(this);
      const auto invoke = *reinterpret_cast<const NativeAllocate *>(table);
      return invoke(reinterpret_cast<FMalloc *>(this), size, allocationTag);
    };
    const auto release = [this](void *pointer)
    {
      const uint32_t table = *reinterpret_cast<const uint32_t *>(this);
      const auto invoke = *reinterpret_cast<const NativeFree *>(table + 8);
      invoke(reinterpret_cast<FMalloc *>(this), pointer);
    };
    auto *object = reinterpret_cast<uint8_t *>(this);
    void *result = allocation; // Native unsigned NewSize>=0 assertion is unconditionally satisfied.
    if (allocation != nullptr && newSize != 0)
    {
      const uint32_t address = reinterpret_cast<uint32_t>(allocation);
      const uint32_t indirect = *reinterpret_cast<const uint32_t *>(object + 0x274 + (address >> 24) * 4);
      const uint32_t pool = indirect + ((address >> 16) & 0xff) * 0x20;
      if (*reinterpret_cast<const uint32_t *>(pool + 0x10) != reinterpret_cast<uint32_t>(object + 0x268))
      {
        const uint32_t table = *reinterpret_cast<const uint32_t *>(pool + 0x10);
        if (newSize > *reinterpret_cast<const uint32_t *>(table + 8) ||
            *reinterpret_cast<const uint32_t *>(object + 0x674 + newSize * 4) !=
                *reinterpret_cast<const uint32_t *>(pool + 0x10))
        {
          result = allocate(newSize, tag); // Virtual slot zero; caller-visible overrides remain active.
          const uint32_t oldTable = *reinterpret_cast<const uint32_t *>(pool + 0x10);
          const uint32_t oldSize = *reinterpret_cast<const uint32_t *>(oldTable + 8); // Reload after Malloc.
          const uint32_t count = MinUnsigned(newSize, oldSize);
          CopyExecutableMemory(result, allocation, count);
          release(allocation); // Virtual slot +8, reloaded after the copy.
        }
      }
      else
      {
        if (newSize > *reinterpret_cast<const uint32_t *>(pool + 4) ||
            newSize * 3u < *reinterpret_cast<const uint32_t *>(pool + 4) * 2u)
        {
          result = allocate(newSize, tag);
          const uint32_t oldSize = *reinterpret_cast<const uint32_t *>(pool);
          const uint32_t count = MinUnsigned(newSize, oldSize);
          CopyExecutableMemory(result, allocation, count);
          release(allocation);
        }
        else
        {
          *reinterpret_cast<uint32_t *>(pool) = newSize;
        }
      }
    }
    else if (newSize != 0)
    {
      result = allocate(newSize, tag);
    }
    else
    {
      if (allocation != nullptr) release(allocation);
      result = nullptr;
    }
    return result;
  }
  // RavenShield.exe @ 10904d73 : RethrowAllocatorReallocPointer
  // Copy-throw the caught pointer from parent EBP-1c into a new throw object at EBP-20.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 10904d87 : UnwindAllocatorReallocFailure
  // Append both the method guard and original pointer/size/tag context, then rethrow without allocation cleanup.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_allocatorReallocGuardName));
    appUnwindf(reinterpret_cast<const uint16_t *>(g_allocatorReallocContextFormat),
               reinterpret_cast<uint32_t>(allocation), newSize, tag);
    throw;
  }
}

// RavenShield.exe data @ 10918db4 : g_allocatorReallocUnwind
const NativeCppUnwindEntry g_allocatorReallocUnwind[2] = {
    {-1, 0},
    {-1, 0},
};

// RavenShield.exe data @ 10918dc4 : g_allocatorReallocCatches
const NativeCppCatchHandler g_allocatorReallocCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x1c, 0x10904d73}, // RethrowAllocatorReallocPointer
    {0, 0, 0, 0x10904d87},                                               // UnwindAllocatorReallocFailure
};

// RavenShield.exe data @ 10918de4 : g_allocatorReallocTryBlocks
const NativeCppTryBlock g_allocatorReallocTryBlocks[1] = {
    {0, 0, 1, 2, NativeAddress(g_allocatorReallocCatches)},
};

// RavenShield.exe data @ 10918df8 : g_allocatorReallocExceptionInfo
const NativeCppFunctionInfo g_allocatorReallocExceptionInfo = {
    0x19930520, 2, NativeAddress(g_allocatorReallocUnwind), 1, NativeAddress(g_allocatorReallocTryBlocks), 0, 0};

// RavenShield.exe @ 10912340 : HandleAllocatorReallocException
// Supply Realloc's two-state pointer/catch-all guard map, without ownership or lock cleanup callbacks.
__declspec(naked) void HandleAllocatorReallocException()
{
  __asm {
    mov eax, offset g_allocatorReallocExceptionInfo
    jmp DispatchExecutableCppException
  }
}
