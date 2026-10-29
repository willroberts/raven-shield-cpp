#include "native_symbols.hpp"
// String accumulator used by launcher object export: FOutputDevice at +0, FString at +4.
#include "container_support.hpp"

class FOutputDevice;
class FStringOutputDevice;

// RavenShield.exe data @ 10916520 : g_stringOutputDeviceVtable
const uint32_t g_stringOutputDeviceVtable[] = {
    NativeAddress(NativeEntry_FStringOutputDevice_Serialize)}; // Serialize; adjacent data starts at +4.

// RavenShield.exe @ 10908e70 : FStringOutputDevice::FStringOutputDevice
// Construct the string before the output base, then install Serialize; no local partial-construction cleanup exists.
FStringOutputDevice::FStringOutputDevice(const uint16_t *text)
{
  const auto constructString = *reinterpret_cast<void(__thiscall **)(FString *, const uint16_t *)>(
      NativeAddress(NativeImport_FStringConstructText));
  constructString(reinterpret_cast<FString *>(reinterpret_cast<uint8_t *>(this) + 4), text);
  const auto constructOutput =
      *reinterpret_cast<void(__thiscall **)(FOutputDevice *)>(NativeAddress(NativeImport_FOutputDeviceConstruct));
  constructOutput(reinterpret_cast<FOutputDevice *>(this));
  *reinterpret_cast<uint32_t *>(this) = reinterpret_cast<uint32_t>(g_stringOutputDeviceVtable);
} // Native ECX receiver is returned in EAX; RET 4 consumes text.

// RavenShield.exe @ 10908e40 : FStringOutputDevice::~FStringOutputDevice
// Destroy only the FString base, retaining the native null-preserving +4 base conversion.
FStringOutputDevice::~FStringOutputDevice() noexcept(false)
{
  FString *string = this ? reinterpret_cast<FString *>(reinterpret_cast<uint8_t *>(this) + 4) : nullptr;
  const auto destroy = *reinterpret_cast<void(__thiscall **)(FString *)>(NativeAddress(NativeImport_FStringDestroy));
  destroy(string);
}

// RavenShield.exe @ 10908ea0 : FStringOutputDevice::Serialize
// Append the text to the FString base without a separator, event filtering or local exception cleanup.
void FStringOutputDevice::Serialize(const uint16_t *text, int32_t event)
{
  const auto append = *reinterpret_cast<FString &(__thiscall **)(FString *, const uint16_t *)>(
      NativeAddress(NativeImport_FStringAppendText));
  append(reinterpret_cast<FString *>(reinterpret_cast<uint8_t *>(this) + 4), text);
} // Event is ignored; native RET 8 consumes both words.
