#pragma once
#include <cstdint>

class WObjectProperties;
class WConfigProperties;
void ConstructExecObjectPropertiesInline(WObjectProperties *storage, uint32_t nameWord);
void ConstructExecConfigPropertiesInline(WConfigProperties *storage, uint32_t nameWord, const uint16_t *title);
