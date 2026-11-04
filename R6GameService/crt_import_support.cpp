#include "native_addresses.h"
#include "native_import_bindings.h"
#include "native_records.h"

// Selected CRT import tails. Each body preserves incoming stack/registers/flags and all unnamed arguments.
// Imported library implementations and host side effects remain outside these native body views.

// Forwards the original memory argument to the current CRT free import.
// R6GameService.dll @ 10033a1c : complete six-byte native current-IAT tail, no wrapper frame.
__declspec(naked) void __cdecl free(void *memory)
{
  __asm {
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCR71_freeSlot
  }
}

namespace R6GameServiceImports {
// Bind the current import pointer directly; the native entry only jumps through this IAT cell.
// R6GameService.dll @ 10033a6c : six-byte compiler import tail; typed live-IAT representation.
Strncpy &strncpy{*reinterpret_cast<Strncpy *>(R6GameServiceAddresses::MSVCR71_strncpySlot)};
}

namespace R6GameServiceImports {
// Bind the current import pointer directly; the native entry only jumps through this IAT cell.
// R6GameService.dll @ 10033a72 : six-byte compiler import tail; typed live-IAT representation.
Strncmp &strncmp{*reinterpret_cast<Strncmp *>(R6GameServiceAddresses::MSVCR71_strncmpSlot)};
}

// Forwards the complete variadic snprintf argument stream without rebuilding it.
// R6GameService.dll @ 10033a78 : complete six-byte native current-IAT tail, no wrapper frame.
__declspec(naked) int __cdecl _snprintf(char *destination,size_t count,const char *format,...)
{
  __asm {
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCR71__snprintfSlot
  }
}

namespace R6GameServiceImports {
// Bind the current import pointer directly; the native entry only jumps through this IAT cell.
// R6GameService.dll @ 10033a7e : six-byte compiler import tail; typed live-IAT representation.
Sprintf &sprintf{*reinterpret_cast<Sprintf *>(R6GameServiceAddresses::MSVCR71_sprintfSlot)};
}

namespace R6GameServiceImports {
// Bind the current import pointer directly; the native entry only jumps through this IAT cell.
// R6GameService.dll @ 10033a84 : six-byte compiler import tail; typed live-IAT representation.
Printf &printf{*reinterpret_cast<Printf *>(R6GameServiceAddresses::MSVCR71_printfSlot)};
}

// Forwards the original text pointer and raw imported integer result.
// R6GameService.dll @ 10033a8a : complete six-byte native current-IAT tail, no wrapper frame.
__declspec(naked) int __cdecl atoi(const char *text)
{
  __asm {
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCR71_atoiSlot
  }
}

// Forwards both original path pointers to the current rename import.
// R6GameService.dll @ 10033a90 : complete six-byte native current-IAT tail, no wrapper frame.
__declspec(naked) int __cdecl rename(const char *oldName,const char *newName)
{
  __asm {
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCR71_renameSlot
  }
}

// Forwards the unchanged path pointer to the current remove import.
// R6GameService.dll @ 10033a96 : complete six-byte native current-IAT tail, no wrapper frame.
__declspec(naked) int __cdecl remove(const char *path)
{
  __asm {
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCR71_removeSlot
  }
}

// Forwards the four original fread arguments and raw imported count result.
// R6GameService.dll @ 10033a9c : complete six-byte native current-IAT tail, no wrapper frame.
__declspec(naked) size_t __cdecl fread(void *buffer,size_t elementSize,size_t count,FILE *stream)
{
  __asm {
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCR71_freadSlot
  }
}

// Forwards the original stream pointer to the current fclose import.
// R6GameService.dll @ 10033aa2 : complete six-byte native current-IAT tail, no wrapper frame.
__declspec(naked) int __cdecl fclose(FILE *stream)
{
  __asm {
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCR71_fcloseSlot
  }
}

// Forwards the original path and mode to the current fopen import.
// R6GameService.dll @ 10033aa8 : complete six-byte native current-IAT tail, no wrapper frame.
__declspec(naked) FILE * __cdecl fopen(const char *path,const char *mode)
{
  __asm {
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCR71_fopenSlot
  }
}

// Forwards the full original character word without narrowing before the imported conversion.
// R6GameService.dll @ 10033c90 : complete six-byte native current-IAT tail, no wrapper frame.
__declspec(naked) int __cdecl toupper(int character)
{
  __asm {
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCR71_toupperSlot
  }
}

// Forwards the four original fwrite arguments and raw imported count result.
// R6GameService.dll @ 10033c96 : complete six-byte native current-IAT tail, no wrapper frame.
__declspec(naked) size_t __cdecl fwrite(const void *buffer,size_t elementSize,size_t count,FILE *stream)
{
  __asm {
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCR71_fwriteSlot
  }
}

namespace R6GameServiceImports {
// Bind the current import pointer directly; the native entry only jumps through this IAT cell.
// R6GameService.dll @ 10033c9c : six-byte compiler import tail; typed live-IAT representation.
Memmove &memmove{*reinterpret_cast<Memmove *>(R6GameServiceAddresses::MSVCR71_memmoveSlot)};
}

// Forwards the original allocation count and element size without adding checks.
// R6GameService.dll @ 10033cae : complete six-byte native current-IAT tail, no wrapper frame.
__declspec(naked) void * __cdecl calloc(size_t count,size_t elementSize)
{
  __asm {
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCR71_callocSlot
  }
}

// Forwards pure-virtual dispatch failure to the current CRT handler without imposing extra termination policy.
// R6GameService.dll @ 10033cb4 : complete six-byte native current-IAT tail, no wrapper frame.
__declspec(naked) int __cdecl _purecall(void)
{
  __asm {
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCR71__purecallSlot
  }
}

namespace R6GameServiceImports {
// Bind the current import pointer directly; the native entry only jumps through this IAT cell.
// R6GameService.dll @ 10033cba : six-byte compiler import tail; typed live-IAT representation.
Time &time{*reinterpret_cast<Time *>(R6GameServiceAddresses::MSVCR71_timeSlot)};
}

// Forwards the original time arguments, leaving the imported x87 result untouched.
// R6GameService.dll @ 10033cc0 : complete six-byte native current-IAT tail, no wrapper frame.
__declspec(naked) double __cdecl difftime(time_t end,time_t begin)
{
  __asm {
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCR71_difftimeSlot
  }
}

// Forwards all five RTTI-cast arguments and retains the imported pointer result.
// R6GameService.dll @ 10033cc6 : complete six-byte native current-IAT tail, no wrapper frame.
__declspec(naked) void * __cdecl __RTDynamicCast(void *object,int vfDelta,void *sourceType,void *targetType,int isReference)
{
  __asm {
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCR71___RTDynamicCastSlot
  }
}

namespace R6GameServiceImports {
// Bind the current import pointer directly; the native entry only jumps through this IAT cell.
// R6GameService.dll @ 10033db4 : six-byte compiler import tail; typed live-IAT representation.
Strtok &strtok{*reinterpret_cast<Strtok *>(R6GameServiceAddresses::MSVCR71_strtokSlot)};
}

// Tail current rand import with original return address/unnamed machine state; no local PRNG state.
// R6GameService.dll @ 10062290 : complete native control/access order and raw ABI retained.
__declspec(naked) int __cdecl rand(void)
{
  __asm {
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCR71_randSlot
  }
}

// Tail current srand import with the complete original seed word and stack; raw import effects pass through.
// R6GameService.dll @ 10062296 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl srand(uint seed)
{
  __asm {
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCR71_srandSlot
  }
}

// Tail current memset import with original destination/value/count; no local fill or argument truncation.
// R6GameService.dll @ 1006229c : complete native control/access order and raw ABI retained.
__declspec(naked) void *__cdecl memset(void *destination,int value,size_t count)
{
  __asm {
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCR71_memsetSlot
  }
}

namespace R6GameServiceImports {
// Bind the current import pointer directly; the native entry only jumps through this IAT cell.
// R6GameService.dll @ 10062336 : six-byte compiler import tail; typed live-IAT representation.
SecurityErrorHandler &__security_error_handler{
  *reinterpret_cast<SecurityErrorHandler *>(R6GameServiceAddresses::MSVCR71___security_error_handlerSlot)
};
}

// Tail current fflush import with original stream pointer and raw imported result.
// R6GameService.dll @ 10063030 : complete native control/access order and raw ABI retained.
__declspec(naked) int __cdecl fflush(FILE *stream)
{
  __asm {
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCR71_fflushSlot
  }
}

// Tail current fprintf import without rebuilding or dropping unnamed variadic words.
// R6GameService.dll @ 10063036 : complete native control/access order and raw ABI retained.
__declspec(naked) int __cdecl fprintf(FILE *stream,const char *format,...)
{
  __asm {
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCR71_fprintfSlot
  }
}

// Tail current gmtime import with original time pointer and raw result; imported tm storage remains external.
// R6GameService.dll @ 1006303c : complete native control/access order and raw ABI retained.
__declspec(naked) tm *__cdecl gmtime(const time_t *time)
{
  __asm {
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCR71_gmtimeSlot
  }
}

// Native virtual-table prefix: clLadderQueryCallbacksVTable
// R6GameService.dll data @ 10077c04 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clLadderQueryCallbacksVTableRecord {
  R6GameServiceNative::Address _purecall; // +0x00
};
const clLadderQueryCallbacksVTableRecord clLadderQueryCallbacksVTable = {R6GameServiceAddresses::_purecall};

// Native virtual-table prefix: clPersistentCallbacksVTable
// R6GameService.dll data @ 10077c0c : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clPersistentCallbacksVTableRecord {
  R6GameServiceNative::Address _purecall; // +0x00
  R6GameServiceNative::Address _purecall2; // +0x04
  R6GameServiceNative::Address _purecall3; // +0x08
  R6GameServiceNative::Address _purecall4; // +0x0c
};
const clPersistentCallbacksVTableRecord clPersistentCallbacksVTable = {
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
};

// Native virtual-table prefix: clLobbyCallbacksVTable
// R6GameService.dll data @ 10077c24 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clLobbyCallbacksVTableRecord {
  R6GameServiceNative::Address _purecall; // +0x00
  R6GameServiceNative::Address _purecall2; // +0x04
  R6GameServiceNative::Address _purecall3; // +0x08
  R6GameServiceNative::Address _purecall4; // +0x0c
  R6GameServiceNative::Address _purecall5; // +0x10
  R6GameServiceNative::Address _purecall6; // +0x14
  R6GameServiceNative::Address _purecall7; // +0x18
  R6GameServiceNative::Address _purecall8; // +0x1c
  R6GameServiceNative::Address _purecall9; // +0x20
  R6GameServiceNative::Address _purecall10; // +0x24
  R6GameServiceNative::Address _purecall11; // +0x28
  R6GameServiceNative::Address _purecall12; // +0x2c
  R6GameServiceNative::Address _purecall13; // +0x30
  R6GameServiceNative::Address _purecall14; // +0x34
  R6GameServiceNative::Address _purecall15; // +0x38
  R6GameServiceNative::Address _purecall16; // +0x3c
  R6GameServiceNative::Address _purecall17; // +0x40
  R6GameServiceNative::Address _purecall18; // +0x44
  R6GameServiceNative::Address _purecall19; // +0x48
  R6GameServiceNative::Address _purecall20; // +0x4c
  R6GameServiceNative::Address _purecall21; // +0x50
  R6GameServiceNative::Address _purecall22; // +0x54
  R6GameServiceNative::Address _purecall23; // +0x58
  R6GameServiceNative::Address _purecall24; // +0x5c
  R6GameServiceNative::Address _purecall25; // +0x60
  R6GameServiceNative::Address _purecall26; // +0x64
  R6GameServiceNative::Address _purecall27; // +0x68
  R6GameServiceNative::Address _purecall28; // +0x6c
  R6GameServiceNative::Address _purecall29; // +0x70
  R6GameServiceNative::Address _purecall30; // +0x74
  R6GameServiceNative::Address _purecall31; // +0x78
  R6GameServiceNative::Address _purecall32; // +0x7c
  R6GameServiceNative::Address _purecall33; // +0x80
  R6GameServiceNative::Address _purecall34; // +0x84
  R6GameServiceNative::Address _purecall35; // +0x88
  R6GameServiceNative::Address _purecall36; // +0x8c
  R6GameServiceNative::Address _purecall37; // +0x90
  R6GameServiceNative::Address _purecall38; // +0x94
  R6GameServiceNative::Address _purecall39; // +0x98
  R6GameServiceNative::Address _purecall40; // +0x9c
  R6GameServiceNative::Address _purecall41; // +0xa0
  R6GameServiceNative::Address _purecall42; // +0xa4
  R6GameServiceNative::Address _purecall43; // +0xa8
  R6GameServiceNative::Address _purecall44; // +0xac
};
const clLobbyCallbacksVTableRecord clLobbyCallbacksVTable = {
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
};

// Native virtual-table prefix: clFriendsCallbacksVTable
// R6GameService.dll data @ 10077cdc : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clFriendsCallbacksVTableRecord {
  R6GameServiceNative::Address _purecall; // +0x00
  R6GameServiceNative::Address _purecall2; // +0x04
  R6GameServiceNative::Address _purecall3; // +0x08
  R6GameServiceNative::Address _purecall4; // +0x0c
  R6GameServiceNative::Address _purecall5; // +0x10
  R6GameServiceNative::Address _purecall6; // +0x14
  R6GameServiceNative::Address _purecall7; // +0x18
  R6GameServiceNative::Address _purecall8; // +0x1c
  R6GameServiceNative::Address _purecall9; // +0x20
  R6GameServiceNative::Address _purecall10; // +0x24
  R6GameServiceNative::Address _purecall11; // +0x28
  R6GameServiceNative::Address _purecall12; // +0x2c
  R6GameServiceNative::Address _purecall13; // +0x30
  R6GameServiceNative::Address _purecall14; // +0x34
  R6GameServiceNative::Address _purecall15; // +0x38
  R6GameServiceNative::Address _purecall16; // +0x3c
};
const clFriendsCallbacksVTableRecord clFriendsCallbacksVTable = {
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
};
