#include "native_symbols.hpp"
// Typed native constructors select their class, then use the class-owned shared base initialization.
#include "object_support.hpp"

// RavenShield.exe @ 10907ec0 : TObjectIterator<UPackage>::TObjectIterator
// Select UPackage and advance immediately; the native constructor returns the receiver in EAX.
template <>
TObjectIterator<UPackage>::TObjectIterator()
    : FObjectIterator((*reinterpret_cast<UClass *(__cdecl **)()>(NativeAddress(NativeImport_UPackage_StaticClass)))())
{
}

// RavenShield.exe @ 10907f00 : TObjectIterator<UModifier>::TObjectIterator
// Select UModifier and advance immediately, retaining assertion continuation on a null class.
template <>
TObjectIterator<UModifier>::TObjectIterator()
    : FObjectIterator((*reinterpret_cast<UClass *(__cdecl **)()>(NativeAddress(NativeImport_UModifier_StaticClass)))())
{
}

// RavenShield.exe @ 10907f40 : TObjectIterator<UCombiner>::TObjectIterator
// Select UCombiner and advance immediately, retaining assertion continuation on a null class.
template <>
TObjectIterator<UCombiner>::TObjectIterator()
    : FObjectIterator((*reinterpret_cast<UClass *(__cdecl **)()>(NativeAddress(NativeImport_UCombiner_StaticClass)))())
{
}

// RavenShield.exe @ 10907f80 : TObjectIterator<UShader>::TObjectIterator
// Select UShader and advance immediately, retaining assertion continuation on a null class.
template <>
TObjectIterator<UShader>::TObjectIterator()
    : FObjectIterator((*reinterpret_cast<UClass *(__cdecl **)()>(NativeAddress(NativeImport_UShader_StaticClass)))())
{
}

// RavenShield.exe @ 10908f90 : TObjectIterator<UEngine>::TObjectIterator
// Select UEngine and advance immediately, retaining assertion continuation on a null class.
template <>
TObjectIterator<UEngine>::TObjectIterator()
    : FObjectIterator((*reinterpret_cast<UClass *(__cdecl **)()>(NativeAddress(NativeImport_UEngine_StaticClass)))())
{
}

// RavenShield.exe @ 10908fd0 : TObjectIterator<AActor>::TObjectIterator
// Select AActor and advance immediately, retaining assertion continuation on a null class.
template <>
TObjectIterator<AActor>::TObjectIterator()
    : FObjectIterator((*reinterpret_cast<UClass *(__cdecl **)()>(NativeAddress(NativeImport_AActor_StaticClass)))())
{
}
