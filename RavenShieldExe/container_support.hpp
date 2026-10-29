#pragma once
#include "allocation_support.hpp"
#include "registry_object_info.hpp"

class FArray;
class FString;
class FConfigFile;
class FConfigSection;
template <class Key, class Value> class TMapBase;
template <class Item> class TArray;
extern void __cdecl appFailAssert(const char *expression, const char *file, int32_t line);
extern "C" void DispatchExecutableCppException();
extern const char g_arrayRemoveEndExpression[];
extern const char g_arrayRemoveIndexExpression[];
extern const char g_arrayRemoveNonnegativeExpression[];
extern const char g_arrayTemplateSourcePath[];
extern const char16_t g_configMapHashTag[];
void *__cdecl AllocateStringArraySlot(uint32_t ignoredSize, TArray<FString> *array);
