#include "native_symbols.hpp"
// Map-check packet lifetime; native destruction releases only the owned Message at +8.
#include "map_check.hpp"

// RavenShield.exe @ 10905700 : MAPCHECK::~MAPCHECK
// Destroy Message automatically after the destructor body; Type and Actor have no cleanup or ownership.
MAPCHECK::~MAPCHECK() noexcept(false) {}
