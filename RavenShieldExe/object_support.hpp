#pragma once
#include <cstdint>

class UObject;
class UClass;
class UPackageMap;
class URenderDevice;
class UEngine;
class UPackage;
class UModifier;
class UCombiner;
class UShader;
class AActor;
class FObjectIterator;
template <class T> class TObjectIterator;
extern const char g_constructObjectSourcePath[];
UClass *__cdecl LoadRenderDeviceClass(UObject *outer, const uint16_t *name, const uint16_t *filename,
                                      uint32_t loadFlags, UPackageMap *sandbox);
URenderDevice *__cdecl ConstructRenderDevice(UClass *type, UObject *outer, uint32_t nameWord, uint32_t flags);
UEngine *__cdecl ConstructEngine(UClass *type, UObject *outer, uint32_t nameWord, uint32_t flags);
int32_t __cdecl ParseClass(const uint16_t *stream, const uint16_t *match, UClass *&result, UObject *outer);
