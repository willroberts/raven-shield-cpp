#include "native_addresses.h"
#include "module_data.h"

// R6Game.dll data @ 100170c0 : shared read-only binary32 constant used by x87 arithmetic
const float NativeFloatFive = 5.0f;

// These are native record-word snapshots, not recovered CRT C++ declarations. Pointer words carry native HIGHLOW
// relocations. RTTI descriptor word +4 stays writable and its private runtime ownership is not invented here.

// R6Game.dll data @ 10024168 : exported writable UTF-16 package-name array
unsigned short GPackage[7] = {'R', '6', 'G', 'a', 'm', 'e', 0};

// R6Game.dll data @ 10024114 : writable RTTI descriptor for .PAX
unsigned int VoidPointerTypeDescriptor[4] = {
    R6GameAddresses::TypeInfo_vftable, // +0x0: type_info vtable at 0x10019aec
    0x0, // +0x4: initial runtime word +4
    0x5841502e, // +0x8: ASCII .PAX name bytes
    0x0, // +0xc: name terminator and padding
};

// R6Game.dll data @ 10024124 : writable RTTI descriptor for .PAG
unsigned int UnsignedShortPointerTypeDescriptor[4] = {
    R6GameAddresses::TypeInfo_vftable, // +0x0: type_info vtable at 0x10019aec
    0x0, // +0x4: initial runtime word +4
    0x4741502e, // +0x8: ASCII .PAG name bytes
    0x0, // +0xc: name terminator and padding
};

// R6Game.dll data @ 10019d40 : read-only void-pointer catchable-type record
const unsigned int VoidPointerCatchableType[7] = {
    0x1, // +0x0: simple-value flags
    R6GameAddresses::VoidPointerTypeDescriptor, // +0x4: VoidPointerTypeDescriptor
    0x0, // +0x8: member displacement
    0xffffffff, // +0xc: no virtual-base table displacement
    0x0, // +0x10: virtual-base displacement
    0x4, // +0x14: four-byte value size
    0x0, // +0x18: no copy callback
};

// R6Game.dll data @ 10019d5c : read-only unsigned-short-pointer catchable-type record
const unsigned int UnsignedShortPointerCatchableType[7] = {
    0x1, // +0x0: simple-value flags
    R6GameAddresses::UnsignedShortPointerTypeDescriptor, // +0x4: UnsignedShortPointerTypeDescriptor
    0x0, // +0x8: member displacement
    0xffffffff, // +0xc: no virtual-base table displacement
    0x0, // +0x10: virtual-base displacement
    0x4, // +0x14: four-byte value size
    0x0, // +0x18: no copy callback
};

// R6Game.dll data @ 10019d78 : read-only catchable-type array, typed pointer then void pointer
const unsigned int UnsignedShortPointerCatchableTypes[3] = {
    0x2, // +0x0: two catchable records
    R6GameAddresses::UnsignedShortPointerCatchableType, // +0x4: UnsignedShortPointerCatchableType
    R6GameAddresses::VoidPointerCatchableType, // +0x8: VoidPointerCatchableType
};

// R6Game.dll data @ 10019d84 : shared read-only throw descriptor
const unsigned int UnsignedShortPointerThrowInfo[4] = {
    0x0, // +0x0: attributes
    0x0, // +0x4: no unwind callback
    0x0, // +0x8: no forward-compatibility callback
    R6GameAddresses::UnsignedShortPointerCatchableTypes, // +0xc: UnsignedShortPointerCatchableTypes
};
