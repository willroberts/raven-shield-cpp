#include "native_shared_entries.hpp"
#include "native_member_entries.hpp"
#include "native_runtime_entries.hpp"
#include "native_import_slots.hpp"

// R6Engine.dll @ 10042b84 : type_info::~type_info
// Forwards the original receiver and stack directly to the imported MSVCR71 type_info destructor.
// Native ABI tail keeps the original ECX and caller frame for imported destruction.
__declspec(naked) void __thiscall type_info::~type_info(type_info* this)
{
    __asm {
        jmp dword ptr [type_infoDestructorImport]
    }
}

// R6Engine.dll @ 10042750 : type_info::DeletingDestructor
// Destroys one type descriptor or a cookie-counted array, optionally frees storage and returns its pointer.
void* __thiscall type_info::DeletingDestructor(uint flags)
{
    // Native captures only the low byte and consumes the full word with RET4.
    byte deleteFlags = reinterpret_cast<byte&>(flags);
    using Destructor = void (__thiscall*)(void*);
    if ((deleteFlags & 2U) != 0) {
        Destructor destroy = (Destructor)&type_infoDestructorNativeEntry;
        byte* cookie = (byte*)this - 4; // Native forms the cookie before reading its raw count.
        int count = *(int*)cookie;
        // Native stride, not an invented complete type layout.
        _eh_vector_destructor_iterator_(this, 0xc, count, destroy);
        if ((deleteFlags & 1U) != 0) FreeThroughGlobalAllocator(cookie);
        return cookie;
    }
    type_info::~type_info(this);
    if ((deleteFlags & 1U) != 0) FreeThroughGlobalAllocator(this); // Unsized free on both paths.
    return this;
}
