// Descriptive aliases for existing four-byte PE32 IAT slots, not additional globals or provider signatures.
// R6Abstract.dll import @ 100053d4 : MSVCR71.dll ??1type_info@@UAE@XZ
extern void *crtTypeInfoDestructorImport;

// Native RTTI descriptor storage: selected PE32 virtual-table address, spare word, and decorated type name.
struct NativePointerTypeDescriptor {
  NativeImageWord32 virtualTable;
  uint spare;
  char typeName[5];
};
// R6Abstract.dll data @ 1000d090 : RTTI void-pointer descriptor
NativePointerTypeDescriptor voidPointerTypeDescriptor = {&type_info_vftable, 0, ".PAX"};
// R6Abstract.dll data @ 1000d0a0 : RTTI unsigned-short-pointer descriptor
NativePointerTypeDescriptor wideStringPointerTypeDescriptor = {&type_info_vftable, 0, ".PAG"};

// R6Abstract.dll data @ 10006cfc : catchable pointer metadata: flags, TypeDescriptor, PMD triple, value size, copy
// function
const NativeCatchableType wideStringPointerCatchableType = {
  .properties = 0x00000001, .typeDescriptor = &wideStringPointerTypeDescriptor,
  .adjustment = {.memberDisplacement = 0x00000000, .vbtableDisplacement = -1,
                 .displacementInVbtable = 0x00000000},
  .valueSize = 0x00000004, .copyFunction = 0x00000000,
};

// R6Abstract.dll data @ 10006ce0 : catchable pointer metadata: flags, TypeDescriptor, PMD triple, value size, copy
// function
const NativeCatchableType voidPointerCatchableType = {
  .properties = 0x00000001, .typeDescriptor = &voidPointerTypeDescriptor,
  .adjustment = {.memberDisplacement = 0x00000000, .vbtableDisplacement = -1,
                 .displacementInVbtable = 0x00000000},
  .valueSize = 0x00000004, .copyFunction = 0x00000000,
};

// R6Abstract.dll data @ 10006b80 : type descriptor virtual dispatch entry Only the deletion slot is supported; the
// following zero word is not declared as another slot.
const NativeTypeInfoVTable type_info_vftable = {
  .VectorDeletingDestructor = &type_info::VectorDeletingDestructor,
};

// R6Abstract.dll @ 10003f3e : destroy the type descriptor through the imported CRT implementation
__declspec(naked) void __thiscall type_info::~type_info(type_info *this) {
  __asm {
    jmp dword ptr [crtTypeInfoDestructorImport]
  }
}

// R6Abstract.dll @ 10003c42 : destroy one type descriptor or an array and optionally release its allocation Descriptive
// compiler-generated name; both native release paths use the module allocator wrapper.
void *__thiscall type_info::VectorDeletingDestructor(type_info *this, uint deletionFlags) {
  if ((deletionFlags & 2) != 0) {
    byte *allocation = (byte *)this - 4;
    int elementCount = *(int *)allocation;
    _eh_vector_destructor_iterator_(this, 12, elementCount, (ArrayElementDestructor)&type_info::~type_info);
    if ((deletionFlags & 1) != 0)
      FreeThroughGlobalAllocator(allocation);
    return allocation;
  }
  this->type_info::~type_info();
  if ((deletionFlags & 1) != 0)
    FreeThroughGlobalAllocator(this);
  return this;
}
