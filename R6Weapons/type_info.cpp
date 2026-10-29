// Aliases for existing PE32 IAT cells; each holds one four-byte imported address.
// R6Weapons.dll import @ 10006234 : MSVCR71.dll ??1type_info@@UAE@XZ
extern uint crtTypeInfoDestructorImport;

// R6Weapons.dll data @ 10007680 : type_info vtable complete-object-locator prefix
// The prefix precedes the callable table; it is not a virtual function slot.
const NativeImageWord32 typeInfoVtableLocator[1] = {&typeInfoCompleteObjectLocator};

// R6Weapons.dll data @ 10007684 : type_info virtual dispatch table
// Its sole callable slot is the reviewed vector-deleting destructor.
const NativeImageWord32 typeInfoVtable[1] = {&type_info::VectorDeletingDestructor};

// R6Weapons.dll data @ 10007720 : type_info RTTI base descriptor
// Describes the sole type_info base, with no virtual-base adjustment.
const NativeRttiBaseDescriptor typeInfoBaseDescriptor = {
    .typeDescriptor = &typeInfoTypeDescriptor,
    .containedBaseCount = 0,
    .adjustment = {.memberDisplacement = 0, .vbtableDisplacement = -1, .displacementInVbtable = 0},
    .attributes = 0,
};

// R6Weapons.dll data @ 10007738 : type_info RTTI base-descriptor array
// The hierarchy's count is one; the following zero word is outside this array view.
const NativeImageWord32 typeInfoBaseDescriptors[1] = {&typeInfoBaseDescriptor};

// R6Weapons.dll data @ 10007740 : type_info RTTI class hierarchy
// Words: signature, attributes, base count, base-descriptor-array address.
const NativeRttiClassHierarchy typeInfoClassHierarchy = {
    .signature = 0,
    .attributes = 0,
    .baseCount = 1,
    .baseDescriptors = &typeInfoBaseDescriptors,
};

// R6Weapons.dll data @ 10007750 : type_info RTTI complete-object locator
// Words: signature, object offset, construction displacement, type descriptor, hierarchy address.
const NativeRttiCompleteObjectLocator typeInfoCompleteObjectLocator = {
    .signature = 0,
    .objectOffset = 0,
    .constructionDisplacement = 0,
    .typeDescriptor = &typeInfoTypeDescriptor,
    .hierarchy = &typeInfoClassHierarchy,
};

// Native descriptor vptr, mutable spare word, decorated name, terminator and trailing zero byte.
struct NativeTypeInfoTypeDescriptor {
  NativeImageWord32 virtualTable;
  uint spare;
  char typeName[16];
};
// R6Weapons.dll data @ 1000c0b0 : type_info RTTI type descriptor
NativeTypeInfoTypeDescriptor typeInfoTypeDescriptor = {
    .virtualTable = &typeInfoVtable,
    .spare = 0,
    .typeName = ".?AVtype_info@@",
};

// R6Weapons.dll @ 1000532e : tail-transfer type_info destruction to the imported CRT implementation
// Preserves the thiscall receiver in ECX and the incoming stack without adding a destructor call or return path.
__declspec(naked) void __thiscall type_info::~type_info(type_info *this) {
  __asm {
    jmp dword ptr ds:[crtTypeInfoDestructorImport]
  }
}

// R6Weapons.dll @ 1000503e : destroy one type_info or a counted array and optionally free its allocation
// RTTI vtable 0x10007684 identifies this wrapper; mask 2 selects arrays, mask 1 frees through current GMalloc.
void *__thiscall type_info::VectorDeletingDestructor(type_info *this, uint deleteFlags) {
  byte flags = (byte)deleteFlags;
  if ((flags & 2) != 0) {
    byte *allocation = (byte *)this - 4;
    int elementCount = *(int *)allocation;
    using ElementDestructor = void(__thiscall *)(type_info *);
    using ArrayDestructorIterator = void(__stdcall *)(void *, uint, int, ElementDestructor);
    ArrayDestructorIterator destroyElements = (ArrayDestructorIterator)&_eh_vector_destructor_iterator_;
    ElementDestructor destroyElement =
        reinterpret_cast<ElementDestructor>(&type_info::~type_info); // Local imported type_info destructor thunk.
    destroyElements(this, 0x0c, elementCount, destroyElement);
    if ((flags & 1) != 0)
      FreeThroughGlobalAllocator(allocation);
    return allocation;
  }
  type_info::~type_info(this);
  if ((flags & 1) != 0)
    FreeThroughGlobalAllocator(this);
  return this;
}
