#include "native_symbols.hpp"
// Native primitive/pointer type descriptors and compiler-generated throw metadata shared by executable guards.
#include "type_metadata.hpp"

// RavenShield.exe data @ 1091f0b0 : g_voidPointerTypeDescriptor
NativeTypeDescriptor<8> g_voidPointerTypeDescriptor = {NativeAddress(g_typeInfoDeletingSlot), 0, ".PAX"};
// RavenShield.exe data @ 1091f0c0 : g_utf16PointerTypeDescriptor
NativeTypeDescriptor<8> g_utf16PointerTypeDescriptor = {NativeAddress(g_typeInfoDeletingSlot), 0, ".PAG"};
// RavenShield.exe data @ 1091f0d0 : g_intTypeDescriptor
NativeTypeDescriptor<4> g_intTypeDescriptor = {NativeAddress(g_typeInfoDeletingSlot), 0, ".H"};

// RavenShield.exe data @ 109185d4 : g_voidPointerCatchableType
// The pointer throw can also match void*; preserve its native four-byte simple-copy and identity adjustment words.
const NativeCatchableType g_voidPointerCatchableType = {
    1, NativeAddress(g_voidPointerTypeDescriptor), {0, -1, 0}, 4, 0};
// RavenShield.exe data @ 109185f0 : g_utf16PointerCatchableType
const NativeCatchableType g_utf16PointerCatchableType = {
    1, NativeAddress(g_utf16PointerTypeDescriptor), {0, -1, 0}, 4, 0};
// RavenShield.exe data @ 1091860c : g_utf16PointerCatchableTypes
// Native order is unsigned-short pointer first, void pointer second; no copy/unwind callback is installed.
const NativeCatchableTypeArray<2> g_utf16PointerCatchableTypes = {
    2, {NativeAddress(g_utf16PointerCatchableType), NativeAddress(g_voidPointerCatchableType)}};
// RavenShield.exe data @ 10918618 : g_utf16PointerThrowInfo
const NativeThrowInfo g_utf16PointerThrowInfo = {0, 0, 0, NativeAddress(g_utf16PointerCatchableTypes)};

// RavenShield.exe data @ 1091884c : g_intCatchableType
const NativeCatchableType g_intCatchableType = {1, NativeAddress(g_intTypeDescriptor), {0, -1, 0}, 4, 0};
// RavenShield.exe data @ 10918868 : g_intCatchableTypes
const NativeCatchableTypeArray<1> g_intCatchableTypes = {1, {NativeAddress(g_intCatchableType)}};
// RavenShield.exe data @ 10918870 : g_intThrowInfo
// Guarded Windows error serialization throws integer one using this native four-byte payload graph.
const NativeThrowInfo g_intThrowInfo = {0, 0, 0, NativeAddress(g_intCatchableTypes)};
