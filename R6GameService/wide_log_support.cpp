#include "native_addresses.h"
#include "native_records.h"

// R6GameService.dll data @ 1007ae48 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo WideStringInsertionExceptionHandlerFunctionInfo;
// R6GameService.dll data @ 1007b44c : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo WideLogStreamDestructorExceptionHandlerFunctionInfo;
// R6GameService.dll data @ 1007b478 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo WideLogStreamConstructorExceptionHandlerFunctionInfo;
// R6GameService.dll data @ 1007b4e0 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo AnsiWideInsertionExceptionHandlerFunctionInfo;
// R6GameService.dll data @ 1007b634 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo WideLogFlushExceptionHandlerFunctionInfo;
// R6GameService.dll data @ 1007b658 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo WideLogWriterExceptionHandlerFunctionInfo;

// Writes extracted wide-buffer text, destroys it, then resets the buffer through a separately owned empty string.
// R6GameService.dll @ 10004ec0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall GetAndClearWideLogBuffer(void *buffer)
{
  __asm {
    // ESP-based EH: nominal unwind EBP is entry ESP. No cleanup is live before the imported getter returns.
    push   0xffffffff
    push   R6GameServiceAddresses::WideLogFlushExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x3c
    push   esi
    // Supply hidden return storage at entryESP-0x28; cache buffer receiver in ESI across callbacks.
    lea    eax,[esp+0x24]
    push   eax
    mov    esi,ecx
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71__basic_stringbuf_strSlot
    // Reload buffer+0x48 after getter; writer receives raw returned EAX, while cleanup still owns local storage.
    mov    ecx,DWORD PTR [esi+0x48]
    push   eax
    mov    DWORD PTR [esp+0x4c],0x0
    call   R6GameServiceAddresses::WriteWideTextToUpdateServiceLog
    // End first lifetime before imported destructor; do not retain it through reset-string construction.
    lea    ecx,[esp+0x24]
    mov    DWORD PTR [esp+0x48],0xffffffff
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Destroy_basic_stringSlot
    // Build empty text from a zero UTF-16 local at entryESP-0x48 into a separate string at-0x44.
    lea    ecx,[esp+0x4]
    push   ecx
    lea    ecx,[esp+0xc]
    mov    WORD PTR [esp+0x8],0x0
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Construct_basic_stringSlot2
    // Only reset-string lifetime1 covers buffer.str(empty); original buffer receiver remains cached.
    lea    edx,[esp+0x8]
    push   edx
    mov    ecx,esi
    mov    DWORD PTR [esp+0x4c],0x1
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71__basic_stringbuf_strSlot2
    // End reset-string lifetime before destructor; return exactly EAX0 after restoring local temporaries.
    lea    ecx,[esp+0x8]
    mov    DWORD PTR [esp+0x48],0xffffffff
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Destroy_basic_stringSlot
    mov    ecx,DWORD PTR [esp+0x40]
    xor    eax,eax
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x48
    ret
  }
}

// Opens updateservice.log with mode8, inserts the supplied wide string/newline and destroys the file without status gates.
// R6GameService.dll @ 10004f60 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall WriteWideTextToUpdateServiceLog(void *unusedReceiver,void *wideText)
{
  __asm {
    // Incoming ECX is ignored; ESP-based EH owns a local wide ofstream at entryESP-0xa0.
    push   0xffffffff
    push   R6GameServiceAddresses::WideLogWriterExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x94
    // Constructor arguments: ANSI filename, mode8, protection0x1b6, hidden virtual-base flag1; no open-status gate.
    push   0x1
    push   0x1b6
    push   0x8
    push   R6GameServiceAddresses::TextUpdateserviceLog
    lea    ecx,[esp+0x10]
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Construct_basic_ofstreamSlot
    // Load endl and original text argument after constructor; stage manipulator before cdecl wide-string insertion.
    mov    eax,ds:R6GameServiceAddresses::MSVCP71_std_endlSlot
    mov    ecx,DWORD PTR [esp+0xa4]
    push   eax
    push   ecx
    lea    edx,[esp+0x8]
    push   edx
    mov    DWORD PTR [esp+0xa8],0x0
    call   R6GameServiceAddresses::InsertPaddedWideString
    add    esp,0x8
    mov    ecx,eax
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_6_basic_ostreamSlot
    // Lower state to-1 before full ofstream destruction; retain raw destructor EAX and restore FS.
    lea    ecx,[esp]
    mov    DWORD PTR [esp+0x9c],0xffffffff
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits__D_basic_ofstreamSlot
    mov    ecx,DWORD PTR [esp+0x94]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0xa0
    ret    0x4
  }
}

// Tail-destroys extracted log text at inherited parent EBP-0x28.
// R6GameService.dll @ 100636a0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyExtractedWideLogText(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Destroy_basic_stringSlot
  }
}

// Tail-destroys the separately constructed empty reset string at inherited parent EBP-0x44.
// R6GameService.dll @ 100636a9 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyEmptyWideLogText(void)
{
  __asm {
    lea    ecx,[ebp-0x44]
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Destroy_basic_stringSlot
  }
}

// Selects native log-flush metadata with two independent temporary-string lifetimes.
// R6GameService.dll @ 100636b2 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl WideLogFlushExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::WideLogFlushExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Tail-destroys the wide ofstream including virtual bases at inherited parent EBP-0xa0.
// R6GameService.dll @ 100636c0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyWideLogFileStream(void)
{
  __asm {
    lea    ecx,[ebp-0xa0]
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits__D_basic_ofstreamSlot
  }
}

// Selects native log-writer metadata with its full ofstream lifetime.
// R6GameService.dll @ 100636cc : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl WideLogWriterExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::WideLogWriterExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Destroys the wide string buffer, optionally frees its cached allocation for flag bit0 and returns that pointer.
// R6GameService.dll @ 100047d0 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall DeleteWideLogStringBuffer(void *buffer,uint deleteFlags)
{
  __asm {
    // Vtable6bca0 selects this deleter; cached ECX survives actual4300 thunk and late GMalloc lookup.
    push   esi
    mov    esi,ecx
    call   R6GameServiceAddresses::_basic_stringbuf
    test   BYTE PTR [esp+0x8],0x1
    je Branch1
    mov    eax,ds:R6GameServiceAddresses::Core__GMallocSlot
    mov    ecx,DWORD PTR [eax]
    mov    edx,DWORD PTR [ecx]
    push   esi
    call   DWORD PTR [edx+0x8]
  Branch1:
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// Destroys the embedded buffer from the ios receiver and restores ostream vftable using the current vbtable offset.
// R6GameService.dll @ 10004800 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall DestroyWideLogStreamFromIos(void *ios)
{
  __asm {
    // ESP-based EH: nominal inherited unwind EBP is entryESP; saved ios pointer at-0x10, state0.
    push   0xffffffff
    push   R6GameServiceAddresses::WideLogStreamDestructorExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   esi
    mov    esi,ecx
    mov    DWORD PTR [esp+0x4],esi
    // Embedded stringbuf starts at ios-0x4c; failure owns ostream unwind at saved ios-0x50.
    lea    ecx,[esi-0x4c]
    mov    DWORD PTR [esp+0x10],0x0
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Destroy_basic_stringbufSlot
    // Reload vbtable and offset after buffer destructor callback; restore imported ostream vftable at base+offset.
    mov    eax,DWORD PTR [esi-0x54]
    mov    ecx,DWORD PTR [eax+0x4]
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits__7_basic_ostreamSlot
    mov    DWORD PTR [ecx+esi*1-0x54],edx
    mov    ecx,DWORD PTR [esp+0x8]
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}

// Constructs the optional virtual ios base, ostream and embedded buffer, then installs log vtables and stream link.
// R6GameService.dll @ 10004880 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall ConstructWideOutputStream(void *object,int constructVirtualBase)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::WideLogStreamConstructorExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x8
    push   esi
    mov    esi,ecx
    mov    ecx,DWORD PTR [esp+0x1c]
    xor    eax,eax
    cmp    ecx,eax
    push   edi
    mov    DWORD PTR [esp+0xc],esi
    mov    DWORD PTR [esp+0x8],eax
    // Nonzero full hidden flag installs vbtable(0,0x54), writes ios_base then basic_ios vftables, owns ios bit0.
    je Branch2
    mov    DWORD PTR [esi],0x1006bcd8
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::MSVCP71_std__7ios_baseSlot
    mov    DWORD PTR [esi+0x54],ecx
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits__7_basic_iosSlot
    mov    DWORD PTR [esi+0x54],edx
    mov    DWORD PTR [esp+0x18],eax
    mov    DWORD PTR [esp+0x8],0x1
  Branch2:
    // Ostream ctor gets object, buffer+8,false,hidden-vbase0; state is0 with owned ios or-1 otherwise.
    push   eax
    push   eax
    lea    edi,[esi+0x8]
    push   edi
    mov    ecx,esi
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Construct_basic_ostreamSlot
    // Reload current vbtable offset after ostream ctor; install deleting vtable6bcd4 at adjusted subobject.
    mov    eax,DWORD PTR [esi]
    mov    ecx,DWORD PTR [eax+0x4]
    mov    DWORD PTR [esi+ecx*1],R6GameServiceAddresses::wide_log_supportDispatchTable2
    // State1 owns ostream before embedded buffer(mode3) construction; no buffer cleanup on partial constructor failure.
    push   0x3
    mov    ecx,edi
    mov    DWORD PTR [esp+0x1c],0x1
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Construct_basic_stringbufSlot
    // Install stringbuf table6bca0 and buffer+0x48 link to object+4; raw EAX returns object.
    mov    ecx,DWORD PTR [esp+0x10]
    lea    edx,[esi+0x4]
    mov    DWORD PTR [edi],R6GameServiceAddresses::wide_log_supportDispatchTable
    mov    DWORD PTR [edi+0x48],edx
    pop    edi
    mov    eax,esi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x14
    ret    0x4
  }
}

// Destroys stream and virtual ios base from the allocation+0x54 view, optionally freeing and returning the cached allocation base.
// R6GameService.dll @ 10004ff0 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall DeleteWideLogStreamFromIos(void *ios,uint deleteFlags)
{
  __asm {
    // Vtable6bcd4 entry: incoming ios is allocation+0x54; cache allocation/ios separately across actual4800.
    push   esi
    lea    esi,[ecx-0x54]
    push   edi
    lea    edi,[esi+0x54]
    mov    ecx,edi
    call   R6GameServiceAddresses::DestroyWideLogStreamFromIos
    // Load current imported ios destructor after stream destructor; flags reload after both callbacks.
    mov    ecx,edi
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Destroy_basic_iosSlot
    test   BYTE PTR [esp+0xc],0x1
    je Branch3
    // Only low flag bit0 frees original allocation through current GMalloc; return allocation regardless helper EAX.
    mov    eax,ds:R6GameServiceAddresses::Core__GMallocSlot
    mov    ecx,DWORD PTR [eax]
    mov    edx,DWORD PTR [ecx]
    push   esi
    call   DWORD PTR [edx+0x8]
  Branch3:
    pop    edi
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// Tail-destroys ostream at the saved ios receiver minus0x50 when embedded-buffer destruction unwinds.
// R6GameService.dll @ 100635d0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyWideLogOstreamDuringDestruction(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    sub    ecx,0x50
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Destroy_basic_ostreamSlot
  }
}

// Selects native stream-destructor metadata for its inherited ostream cleanup.
// R6GameService.dll @ 100635dc : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl WideLogStreamDestructorExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::WideLogStreamDestructorExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Clears virtual-base ownership bit0 before tail-destroying ios at saved object+0x54.
// R6GameService.dll @ 100635f0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyOwnedWideLogIos(void)
{
  __asm {
    // Conditional virtual-base cleanup clears bit0 before imported destructor, retaining other ownership bits.
    mov    eax,DWORD PTR [ebp-0x14]
    and    eax,0x1
    je Branch4
    and    DWORD PTR [ebp-0x14],0xfffffffe
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x54
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Destroy_basic_iosSlot
  Branch4:
    ret
  }
}

// Tail-destroys ostream at saved object+4 during constructor unwind.
// R6GameService.dll @ 1006360d : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyConstructedWideLogOstream(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x4
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Destroy_basic_ostreamSlot
  }
}

// Selects native stream-constructor metadata for ostream and conditional virtual-ios cleanup.
// R6GameService.dll @ 10063619 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl WideLogStreamConstructorExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::WideLogStreamConstructorExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Inserts widened ANSI bytes with native width/fill/error ordering, then branches into shared parent-frame cleanup.
// R6GameService.dll @ 10004920 : complete native control/access order and raw ABI retained.
__declspec(naked) int * __cdecl InsertAnsiTextIntoWideStream(int *stream,const char *text)
{
  __asm {
    // EBP-based EH; state-1. Parent locals: sentry-2c, facet-24, locale-20, remaining-1c, padding-18, error-14.
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::AnsiWideInsertionExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x20
    mov    eax,DWORD PTR [ebp+0xc]
    push   ebx
    push   esi
    push   edi
    xor    ebx,ebx
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x14],ebx
    // Scan to the first NUL before constructing sentry; width/padding use signed 32-bit comparisons.
    lea    edx,[eax+0x1]
    lea    esp,[esp+0x0]
  Branch5:
    mov    cl,BYTE PTR [eax]
    inc    eax
    test   cl,cl
    jne    Branch5
    mov    esi,DWORD PTR [ebp+0x8]
    sub    eax,edx
    mov    edi,eax
    mov    eax,DWORD PTR [esi]
    mov    ecx,DWORD PTR [eax+0x4]
    mov    eax,DWORD PTR [ecx+esi*1+0x18]
    cmp    eax,ebx
    mov    DWORD PTR [ebp-0x1c],edi
    jle    Branch6
    cmp    eax,edi
    jle    Branch6
    sub    eax,edi
    mov    DWORD PTR [ebp-0x18],eax
    jmp    Branch7
  Branch6:
    mov    DWORD PTR [ebp-0x18],ebx
  Branch7:
    // Construct sentry(stream); false sentry sets badbit and jumps directly to4acd without resetting width.
    push   esi
    lea    ecx,[ebp-0x2c]
    call   R6GameServiceAddresses::ConstructWideStreamSentry
    mov    al,BYTE PTR [ebp-0x28]
    test   al,al
    mov    DWORD PTR [ebp-0x4],ebx
    jne    Branch8
    mov    DWORD PTR [ebp-0x14],0x4
    jmp    R6GameServiceAddresses::WideLogConstructorResume
  Branch8:
    // State1 covers try; state2 owns locale from getloc. Facet receives returned EAX, cleanup owns local-20.
    mov    eax,DWORD PTR [esi]
    mov    ecx,DWORD PTR [eax+0x4]
    lea    edx,[ebp-0x20]
    mov    bl,0x1
    push   edx
    add    ecx,esi
    mov    BYTE PTR [ebp-0x4],bl
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_ios_base_getlocSlot
    push   eax
    mov    BYTE PTR [ebp-0x4],0x2
    call   R6GameServiceAddresses::GetOrCreateUnsignedShortCtypeFacet
    add    esp,0x4
    lea    ecx,[ebp-0x20]
    mov    DWORD PTR [ebp-0x24],eax
    mov    BYTE PTR [ebp-0x4],bl
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_std_DestroylocaleSlot
    // Only adjustfield==0x40 defers padding; other flag values pad before text.
    mov    ecx,DWORD PTR [esi]
    mov    edx,DWORD PTR [ecx+0x4]
    mov    eax,DWORD PTR [edx+esi*1+0x10]
    and    eax,0x1c0
    cmp    eax,0x40
    je     Branch11
  Branch9:
    mov    ebx,DWORD PTR [ebp-0x18]
    test   ebx,ebx
    jle    Branch12
    // Each fill iteration reloads current vbtable, fill and streambuf; only low AX==ffff reports failure.
    mov    eax,DWORD PTR [esi]
    mov    ecx,DWORD PTR [eax+0x4]
    lea    eax,[ecx+esi*1]
    xor    edx,edx
    mov    dx,WORD PTR [eax+0x30]
    mov    eax,DWORD PTR [eax+0x28]
    mov    ecx,eax
    push   edx
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71__basic_streambuf_sputcSlot
    cmp    ax,0xffff
    jne    Branch10
    or     DWORD PTR [ebp-0x14],0x4
    jmp    Branch12
  Branch10:
    dec    ebx
    mov    DWORD PTR [ebp-0x18],ebx
    jmp    Branch9
  Branch11:
    mov    ebx,DWORD PTR [ebp-0x18]
  Branch12:
    mov    eax,DWORD PTR [ebp-0x14]
    test   eax,eax
    jne    Branch15
    test   edi,edi
    jle    Branch14
    // Cache streambuf before widening unsigned byte; widening callback cannot redirect this sputc receiver.
    mov    edx,DWORD PTR [esi]
    mov    eax,DWORD PTR [edx+0x4]
    mov    ecx,DWORD PTR [ebp+0xc]
    mov    edi,DWORD PTR [eax+esi*1+0x28]
    xor    edx,edx
    mov    dl,BYTE PTR [ecx]
    mov    ecx,DWORD PTR [ebp-0x24]
    push   edx
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71__ctype_widenSlot
    mov    ecx,edi
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71__basic_streambuf_sputcSlot
    cmp    ax,0xffff
    jne    Branch13
    mov    DWORD PTR [ebp-0x14],0x4
  Branch13:
    // Even failed text sputc decrements remaining count and increments the original argument slot.
    mov    ecx,DWORD PTR [ebp-0x1c]
    mov    eax,DWORD PTR [ebp+0xc]
    dec    ecx
    inc    eax
    mov    DWORD PTR [ebp-0x1c],ecx
    mov    DWORD PTR [ebp+0xc],eax
    mov    edi,ecx
    jmp    Branch11
  Branch14:
    // Deferred padding keeps the cached count in EBX; reloads buffer/fill each iteration.
    test   ebx,ebx
    jle    Branch15
    mov    eax,DWORD PTR [esi]
    mov    ecx,DWORD PTR [eax+0x4]
    lea    eax,[ecx+esi*1]
    xor    edx,edx
    mov    dx,WORD PTR [eax+0x30]
    mov    eax,DWORD PTR [eax+0x28]
    mov    ecx,eax
    push   edx
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71__basic_streambuf_sputcSlot
    cmp    ax,0xffff
    jne    Branch16
    or     DWORD PTR [ebp-0x14],0x4
  Branch15:
    // Reset current stream width before common cleanup; exception path bypasses this store.
    mov    edx,DWORD PTR [esi]
    mov    eax,DWORD PTR [edx+0x4]
    add    eax,esi
    mov    DWORD PTR [eax+0x18],0x0
    jmp    R6GameServiceAddresses::FinishWideStreamInsertCleanup
  Branch16:
    dec    ebx
    jmp    Branch14
  }
}

// Marks the parent stream bad with rethrow enabled and returns the catch-resume address.
// R6GameService.dll @ 10004a9e : complete native control/access order and raw ABI retained.
__declspec(naked) void * __cdecl CatchAnsiWideInsertion(void)
{
  __asm {
    // Inherited parent EBP; retain the redundant null-buffer badbit OR and clear(state|4,true).
    mov    eax,DWORD PTR [ebp+0x8]
    mov    ecx,DWORD PTR [eax]
    mov    ecx,DWORD PTR [ecx+0x4]
    mov    edx,DWORD PTR [ecx+eax*1+0x28]
    add    ecx,eax
    mov    eax,DWORD PTR [ecx+0x8]
    or     eax,0x4
    test   edx,edx
    jne    Branch17
    or     eax,0x4
  Branch17:
    push   0x1
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_ios_base_clearSlot
    mov    eax,R6GameServiceAddresses::ResumeAnsiWideInsertion
    ret
  }
}

// Reloads the parent stream after a catch, then shares normal sentry cleanup and the parent return epilogue.
// R6GameService.dll @ 10004ac8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ResumeAnsiWideInsertion(void)
{
  __asm {
    // Internal catch-resume entry, not an independent callable C++ method; parent stack/register saves remain live.
    mov    esi,DWORD PTR [ebp+0x8]
    // R6GameService.dll @ 10004acb : internal shared label, not a callable method or duplicate body.
  Branch18:
    // Common normal/catch cleanup entry; sentry-false branch skips XOR because EBX already holds zero.
    xor    ebx,ebx
    mov    edx,DWORD PTR [esi]
    mov    ecx,DWORD PTR [edx+0x4]
    mov    edx,DWORD PTR [ebp-0x14]
    add    ecx,esi
    cmp    edx,ebx
    mov    DWORD PTR [ebp-0x4],ebx
    je     Branch20
    mov    eax,DWORD PTR [ecx+0x8]
    or     eax,edx
    cmp    DWORD PTR [ecx+0x28],ebx
    jne    Branch19
    or     eax,0x4
  Branch19:
    push   ebx
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_ios_base_clearSlot
  Branch20:
    // State4 covers uncaught_exception and optional _Osfx; sentry stream is reloaded after callbacks.
    mov    DWORD PTR [ebp-0x4],0x4
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_std_uncaught_exceptionSlot
    test   al,al
    jne    Branch21
    mov    ecx,DWORD PTR [ebp-0x2c]
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71__basic_ostream__OsfxSlot
  Branch21:
    mov    eax,DWORD PTR [ebp-0x2c]
    mov    ecx,DWORD PTR [eax]
    mov    edx,DWORD PTR [ecx+0x4]
    mov    eax,DWORD PTR [edx+eax*1+0x28]
    cmp    eax,ebx
    // End ownership before optional mutex unlock at current streambuf+4.
    mov    DWORD PTR [ebp-0x4],0xffffffff
    je     Branch22
    lea    ecx,[eax+0x4]
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71__Mutex__UnlockSlot
  Branch22:
    // Return cached/current ESI rather than helper EAX; restore parent registers, stack and FS.
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    mov    eax,esi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
  }
}

// Tail-destroys the completed insertion sentry at inherited parent EBP-0x2c.
// R6GameService.dll @ 10063630 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyAnsiInsertionSentry(void)
{
  __asm {
    lea    ecx,[ebp-0x2c]
    jmp    R6GameServiceAddresses::DestroyWideStreamSentry
  }
}

// Tail-destroys the insertion locale at inherited parent EBP-0x20.
// R6GameService.dll @ 10063638 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyAnsiInsertionLocale(void)
{
  __asm {
    lea    ecx,[ebp-0x20]
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCP71_std_DestroylocaleSlot
  }
}

// Tail-unlocks the sentry stream through its saved owner at inherited parent EBP-0x2c.
// R6GameService.dll @ 10063641 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UnlockAnsiInsertionSentry(void)
{
  __asm {
    lea    ecx,[ebp-0x2c]
    jmp    R6GameServiceAddresses::UnlockMutexIfPresent
  }
}

// Selects the insertion operator metadata for its sentry, locale and catchall lifetimes.
// R6GameService.dll @ 10063649 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl AnsiWideInsertionExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::AnsiWideInsertionExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Inserts a CRT wide string with cached length, current storage/buffer reads and native width/error ordering.
// R6GameService.dll @ 10002800 : complete native control/access order and raw ABI retained.
__declspec(naked) int * __cdecl InsertPaddedWideString(int *stream,const void *wideText)
{
  __asm {
    // EBP-based EH: sentry-24/ready-20, cached length-1c, padding-18, error-14 and saved ESP-10.
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::WideStringInsertionExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x18
    // CRT wide-string length+14 is cached before sentry; signed width>0 then unsigned width>length gates padding.
    mov    eax,DWORD PTR [ebp+0xc]
    mov    ecx,DWORD PTR [eax+0x14]
    push   ebx
    push   esi
    mov    esi,DWORD PTR [ebp+0x8]
    mov    edx,DWORD PTR [esi]
    mov    eax,DWORD PTR [edx+0x4]
    mov    eax,DWORD PTR [eax+esi*1+0x18]
    xor    ebx,ebx
    cmp    eax,ebx
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x14],ebx
    mov    DWORD PTR [ebp-0x1c],ecx
    jle    Branch23
    cmp    eax,ecx
    jbe    Branch23
    sub    eax,ecx
    mov    edi,eax
    mov    DWORD PTR [ebp-0x18],edi
    jmp    Branch24
  Branch23:
    mov    DWORD PTR [ebp-0x18],ebx
    mov    edi,ebx
  Branch24:
    // Construct sentry. False readiness sets badbit and jumps directly to2977, retaining width.
    push   esi
    lea    ecx,[ebp-0x24]
    call   R6GameServiceAddresses::ConstructWideStreamSentry
    mov    al,BYTE PTR [ebp-0x20]
    test   al,al
    mov    DWORD PTR [ebp-0x4],0x0
    jne    Branch25
    mov    DWORD PTR [ebp-0x14],0x4
    jmp    R6GameServiceAddresses::FinishWideStringInsert
  Branch25:
    // Try state1; only adjustfield exactly40 defers fill until after text.
    mov    ecx,DWORD PTR [esi]
    mov    edx,DWORD PTR [ecx+0x4]
    mov    eax,DWORD PTR [edx+esi*1+0x10]
    and    eax,0x1c0
    cmp    eax,0x40
    mov    BYTE PTR [ebp-0x4],0x1
    je     Branch28
    jmp    Branch26
    lea    ecx,[ecx+0x0]
  Branch26:
    // Leading fill uses cached EDI count, publishes decrements to local padding and reloads current fill/buffer.
    test   edi,edi
    jbe    Branch27
    mov    eax,DWORD PTR [esi]
    mov    ecx,DWORD PTR [eax+0x4]
    lea    eax,[ecx+esi*1]
    xor    edx,edx
    mov    dx,WORD PTR [eax+0x30]
    mov    eax,DWORD PTR [eax+0x28]
    mov    ecx,eax
    push   edx
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71__basic_streambuf_sputcSlot
    cmp    ax,0xffff
    jne    Branch30
    or     ebx,0x4
    mov    DWORD PTR [ebp-0x14],ebx
  Branch27:
    test   ebx,ebx
    jne    Branch35
  Branch28:
    // Unsigned index against cached length. Every character reloads original argument and capacity.
    xor    edi,edi
    mov    ebx,0x8
  Branch29:
    cmp    edi,DWORD PTR [ebp-0x1c]
    jae    Branch33
    // Capacity<8 selects inline UTF-16 at string+4; otherwise load heap pointer at+4.
    mov    eax,DWORD PTR [ebp+0xc]
    cmp    DWORD PTR [eax+0x18],ebx
    jb     Branch31
    mov    eax,DWORD PTR [eax+0x4]
    jmp    Branch32
  Branch30:
    dec    edi
    mov    DWORD PTR [ebp-0x18],edi
    jmp    Branch26
  Branch31:
    add    eax,0x4
  Branch32:
    // Reload current streambuf before loading UTF-16 word; sputc failure is low AX==ffff.
    mov    edx,DWORD PTR [esi]
    mov    ecx,DWORD PTR [edx+0x4]
    mov    ecx,DWORD PTR [ecx+esi*1+0x28]
    xor    edx,edx
    mov    dx,WORD PTR [eax+edi*2]
    push   edx
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71__basic_streambuf_sputcSlot
    cmp    ax,0xffff
    jne    Branch36
    or     DWORD PTR [ebp-0x14],0x4
  Branch33:
    // Skip deferred fill after any text error; deferred count remains in parent local-18.
    mov    eax,DWORD PTR [ebp-0x14]
    test   eax,eax
    jne    Branch35
  Branch34:
    mov    eax,DWORD PTR [ebp-0x18]
    test   eax,eax
    jbe    Branch35
    mov    eax,DWORD PTR [esi]
    mov    ecx,DWORD PTR [eax+0x4]
    lea    eax,[ecx+esi*1]
    xor    edx,edx
    mov    dx,WORD PTR [eax+0x30]
    mov    eax,DWORD PTR [eax+0x28]
    mov    ecx,eax
    push   edx
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71__basic_streambuf_sputcSlot
    cmp    ax,0xffff
    jne    Branch37
    or     DWORD PTR [ebp-0x14],0x4
  Branch35:
    // Normal insertion resets current width before shared cleanup; false sentry and catch paths bypass this store.
    mov    eax,DWORD PTR [esi]
    mov    eax,DWORD PTR [eax+0x4]
    add    eax,esi
    mov    DWORD PTR [eax+0x18],0x0
    jmp    R6GameServiceAddresses::FinishWideStringInsert
  Branch36:
    // Only successful text output advances EDI; neither text path increments the original string argument slot.
    inc    edi
    jmp    Branch29
  Branch37:
    dec    DWORD PTR [ebp-0x18]
    jmp    Branch34
  }
}

// Marks the inherited parent stream bad with rethrow enabled and returns its catch-resume address.
// R6GameService.dll @ 1000294a : complete native control/access order and raw ABI retained.
__declspec(naked) void * __cdecl CatchWideStringInsert(void)
{
  __asm {
    // Inherited EBP; current stream state/buffer, redundant null-buffer OR4, clear(state|4,true).
    mov    eax,DWORD PTR [ebp+0x8]
    mov    edx,DWORD PTR [eax]
    mov    ecx,DWORD PTR [edx+0x4]
    mov    edx,DWORD PTR [ecx+eax*1+0x28]
    add    ecx,eax
    mov    eax,DWORD PTR [ecx+0x8]
    or     eax,0x4
    test   edx,edx
    jne    Branch38
    or     eax,0x4
  Branch38:
    push   0x1
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_ios_base_clearSlot
    mov    eax,R6GameServiceAddresses::ResumeWideStringInsert
    ret
  }
}

// Reloads the caught stream, then shares sentry cleanup and the insertion parent return epilogue.
// R6GameService.dll @ 10002974 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ResumeWideStringInsert(void)
{
  __asm {
    // Internal catch-resume entry retains parent stack/register saves; reload stream after catch callback.
    mov    esi,DWORD PTR [ebp+0x8]
    // R6GameService.dll @ 10002977 : shared internal label, one canonical continuation body.
  Branch39:
    // Shared live-parent entry; lower state0 before conditional clear(error|state|optional-null-buffer-badbit,false).
    mov    ecx,DWORD PTR [esi]
    mov    ecx,DWORD PTR [ecx+0x4]
    mov    edx,DWORD PTR [ebp-0x14]
    add    ecx,esi
    test   edx,edx
    mov    DWORD PTR [ebp-0x4],0x0
    je     Branch41
    mov    eax,DWORD PTR [ecx+0x8]
    or     eax,edx
    mov    edx,DWORD PTR [ecx+0x28]
    test   edx,edx
    jne    Branch40
    or     eax,0x4
  Branch40:
    push   0x0
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_ios_base_clearSlot
  Branch41:
    // State3 owns unlock-only cleanup while uncaught_exception and optional suffix run; low AL is the gate.
    mov    DWORD PTR [ebp-0x4],0x3
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_std_uncaught_exceptionSlot
    test   al,al
    jne    Branch42
    mov    ecx,DWORD PTR [ebp-0x24]
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71__basic_ostream__OsfxSlot
  Branch42:
    // Reload saved sentry owner, vbtable and buffer after callbacks.
    mov    eax,DWORD PTR [ebp-0x24]
    mov    edx,DWORD PTR [eax]
    mov    ecx,DWORD PTR [edx+0x4]
    mov    eax,DWORD PTR [ecx+eax*1+0x28]
    test   eax,eax
    // Lower state-1 before optional buffer+4 mutex unlock.
    mov    DWORD PTR [ebp-0x4],0xffffffff
    je     Branch43
    lea    ecx,[eax+0x4]
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71__Mutex__UnlockSlot
  Branch43:
    // Return current ESI rather than imported helper EAX; restore saved parent stack/registers and FS.
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    mov    eax,esi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
  }
}

// Tail-destroys the completed wide-string insertion sentry at inherited parent EBP-0x24.
// R6GameService.dll @ 10063250 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyWideStringInsertionSentry(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyWideStreamSentry
  }
}

// Tail-unlocks the wide-string insertion sentry owner at inherited parent EBP-0x24.
// R6GameService.dll @ 10063258 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UnlockWideStringInsertionSentry(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::UnlockMutexIfPresent
  }
}

// Selects the wide-string insertion metadata for its catchall and sentry cleanup states.
// R6GameService.dll @ 10063260 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl WideStringInsertionExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::WideStringInsertionExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Native virtual-table prefix: wide_log_supportDispatchTable
// R6GameService.dll data @ 1006bca0 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct wide_log_supportDispatchTableRecord {
  R6GameServiceNative::Address DeleteWideLogStringBuffer; // +0x00
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember66; // +0x04
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember65; // +0x08
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember64; // +0x0c
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember63; // +0x10
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember62; // +0x14
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember61; // +0x18
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember60; // +0x1c
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember59; // +0x20
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember58; // +0x24
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember57; // +0x28
  R6GameServiceNative::Address GetAndClearWideLogBuffer; // +0x2c
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember56; // +0x30
};
const wide_log_supportDispatchTableRecord wide_log_supportDispatchTable = {
  R6GameServiceAddresses::DeleteWideLogStringBuffer,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember66,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember65,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember64,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember63,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember62,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember61,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember60,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember59,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember58,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember57,
  R6GameServiceAddresses::GetAndClearWideLogBuffer,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember56,
};

// Native virtual-table prefix: wide_log_supportDispatchTable2
// R6GameService.dll data @ 1006bcd4 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct wide_log_supportDispatchTable2Record {
  R6GameServiceNative::Address DeleteWideLogStreamFromIos; // +0x00
};
const wide_log_supportDispatchTable2Record wide_log_supportDispatchTable2 = {
  R6GameServiceAddresses::DeleteWideLogStreamFromIos,
};
