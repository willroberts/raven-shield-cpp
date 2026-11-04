#pragma once

// PE32 import views: these aliases describe library entry ABIs, not implementations of supporting DLLs.
// References to the IAT pointer cells keep later loader/hook replacements visible at each call site.
namespace R6GameServiceImports {
using Strncpy = char * (__cdecl *)(char *,const char *,unsigned int);
using Strncmp = int (__cdecl *)(const char *,const char *,unsigned int);
using Sprintf = int (__cdecl *)(char *,const char *,...);
using Printf = int (__cdecl *)(const char *,...);
using Memmove = void * (__cdecl *)(void *,const void *,unsigned int);
using Time = int (__cdecl *)(int *); // MSVCR71 PE32 time_t is a signed 32-bit word.
using Strtok = char * (__cdecl *)(char *,const char *);
using GetAdaptersInfoFunction = unsigned int (__stdcall *)(void *,unsigned int *);
// Entry-address view only: _ftol consumes live x87 ST(0) and returns EDX:EAX, with no physical stack operands.
using Ftol = long long (__cdecl *)();
using SecurityErrorHandler = void (__cdecl *)(unsigned int,unsigned int); // Physical words; pointee roles unresolved.
extern Strncpy &strncpy;
extern Strncmp &strncmp;
extern Sprintf &sprintf;
extern Printf &printf;
extern Memmove &memmove;
extern Time &time;
extern Strtok &strtok;
extern GetAdaptersInfoFunction &GetAdaptersInfo;
extern Ftol &ftol;
extern SecurityErrorHandler &__security_error_handler;
}
