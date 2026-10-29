#include "native_addresses.h"

// R6Game.dll data @ 10019ae8 : read-only private type_info RTTI graph record
const unsigned int TypeInfoCompleteObjectLocatorPointer[1] = {
    R6GameAddresses::TypeInfoCompleteObjectLocator, // Complete-object locator for the following vtable.
};

// R6Game.dll data @ 10019ba8 : read-only private type_info RTTI graph record
const unsigned int TypeInfoBaseClassDescriptor[6] = {
    R6GameAddresses::TypeInfoTypeDescriptor, // TypeInfoTypeDescriptor address.
    0x0, // No contained base records.
    0x0, // Member displacement.
    0xffffffff, // No virtual-base table displacement.
    0x0, // Virtual-base displacement.
    0x0, // Attributes.
};

// R6Game.dll data @ 10019bc0 : read-only private type_info RTTI graph record
const unsigned int TypeInfoBaseClassArray[1] = {
    R6GameAddresses::TypeInfoBaseClassDescriptor, // TypeInfoBaseClassDescriptor address.
};

// R6Game.dll data @ 10019bc8 : read-only private type_info RTTI graph record
const unsigned int TypeInfoClassHierarchyDescriptor[4] = {
    0x0, // Signature.
    0x0, // Attributes.
    0x1, // One base record.
    R6GameAddresses::TypeInfoBaseClassArray, // TypeInfoBaseClassArray address.
};

// R6Game.dll data @ 10019bd8 : read-only private type_info RTTI graph record
const unsigned int TypeInfoCompleteObjectLocator[5] = {
    0x0, // Signature.
    0x0, // Vtable offset.
    0x0, // Constructor displacement offset.
    R6GameAddresses::TypeInfoTypeDescriptor, // TypeInfoTypeDescriptor address.
    R6GameAddresses::TypeInfoClassHierarchyDescriptor, // TypeInfoClassHierarchyDescriptor address.
};

// R6Game.dll data @ 10024184 : writable RTTI descriptor for class type_info
unsigned int TypeInfoTypeDescriptor[6] = {
    R6GameAddresses::TypeInfo_vftable, // type_info vtable address.
    0x0, // Initial private runtime word.
    0x56413f2e, // Decorated name bytes.
    0x65707974, // Decorated name bytes.
    0x666e695f, // Decorated name bytes.
    0x40406f, // Decorated name terminator.
};

// R6Game.dll data @ 10019aec : type_info virtual-function table
// Preferred-VA code-pointer DWORDs; every native slot has a PE HIGHLOW relocation.
extern const uint TypeInfo_vftable[1] = {
    R6GameAddresses::type_info_VectorDeletingDestructor, // +0x0: type_info::VectorDeletingDestructor
};

// R6Game.dll @ 10013388 : forward RTTI object destruction through the selected CRT import
__declspec(naked) void __thiscall type_info::~type_info(type_info* this)
{
    __asm { jmp dword ptr [R6GameAddresses::MSVCR71_type_info_DestructorSlot] }
}

// R6Game.dll @ 10012f06 : destroy RTTI objects and optionally release their scalar or array allocation
void* __thiscall type_info::VectorDeletingDestructor(type_info* this, uint flags)
{
    byte deleteFlags = (byte)flags;
    if ((deleteFlags & 2) != 0) {
        void* allocation = (byte*)this - 4;
        int elementCount = *(int*)allocation;
        _eh_vector_destructor_iterator_(this, 0x0c, elementCount, &type_info::~type_info);
        if ((deleteFlags & 1) != 0) FreeThroughGlobalAllocator(allocation);
        return allocation;
    }
    type_info::~type_info(this);
    if ((deleteFlags & 1) != 0) FreeThroughGlobalAllocator(this);
    return this;
}
