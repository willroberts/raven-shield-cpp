#include "native_addresses.h"

// Shared cycle clock; the original out-of-line helper identifier is unavailable.
// float10 denotes live x87 values under the inherited precision/rounding mode, without a double/float store.
// R6GameService.dll @ 10005220 : ST(0) result; RDTSC remains an unserialized hardware intrinsic boundary.
float10 ReadCycleTimeSeconds(void)
{
  ulonglong counter = __rdtsc();
  int high = (int)(counter >> 32);
  int low = (int)counter;
  float10 highCycles = (float10)high;
  if (high < 0) highCycles += *(double *)R6GameServiceAddresses::NativeDouble4294967296_0;
  highCycles *= *(double *)R6GameServiceAddresses::NativeDouble4294967296_0;
  float10 lowCycles = (float10)low;
  if (low < 0) lowCycles += *(double *)R6GameServiceAddresses::NativeDouble4294967296_0;
  const double *secondsPerCycle = *(const double **)R6GameServiceAddresses::Core__GSecondsPerCycleSlot;
  float10 seconds = highCycles + lowCycles;
  seconds *= *secondsPerCycle;
  seconds += *(double *)R6GameServiceAddresses::NativeDouble16777216_0;
  return seconds;
}
