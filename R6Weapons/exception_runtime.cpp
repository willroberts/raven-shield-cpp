// Aliases for existing PE32 IAT cells; each holds one four-byte imported address.
// R6Weapons.dll import @ 10006228 : MSVCR71.dll __dllonexit
extern uint crtDllOnExitImport;
// R6Weapons.dll import @ 1000622c : MSVCR71.dll _except_handler3
extern uint crtExceptHandlerImport;
// R6Weapons.dll import @ 10006230 : MSVCR71.dll ?terminate@@YAXXZ
extern uint crtTerminateImport;
// R6Weapons.dll import @ 10006238 : MSVCR71.dll _CxxThrowException
extern uint crtCxxThrowExceptionImport;
// R6Weapons.dll import @ 1000623c : MSVCR71.dll __CxxFrameHandler
extern uint crtCxxFrameHandlerImport;
// R6Weapons.dll import @ 10006244 : MSVCR71.dll _initterm
extern uint crtInitTermImport;
// R6Weapons.dll import @ 10006250 : MSVCR71.dll __CppXcptFilter
extern uint crtCppExceptionFilterImport;

// Numbered unbound records retain separate native identities; their method ownership is unresolved.
// R6Weapons.dll data @ 10007904 : native UnwindMap with no bound dispatcher
// Pairs: signed predecessor state, cleanup entry address.
// Same unwind transitions as frame 0x100078e8; no separate method ownership is assigned.
const NativeCxxUnwindEntry unboundUnwindMap1[2] = {
    {.previousState = -1, .cleanup = &UnwindWeaponConstructorBase},
    {.previousState = 0x00000000, .cleanup = &UnwindWeaponConstructorReticuleClass},
};

// R6Weapons.dll data @ 10007914 : native FuncInfo with no bound dispatcher
// Words: magic, unwind-state count/map, zero try count/map and two zero tail words.
// Same unwind transitions as frame 0x100078e8; no separate method ownership is assigned.
const NativeCxxFramePrefix unboundFuncInfo1 = {
    .magic = 0x19930520,
    .unwindCount = 0x00000002,
    .unwindMap = &unboundUnwindMap1,
    .tryCount = 0x00000000,
    .tryMap = 0x00000000,
    .ipCount = 0x00000000,
    .ipMap = 0x00000000,
};

// R6Weapons.dll data @ 10007988 : native UnwindMap with no bound dispatcher
// Pairs: signed predecessor state, cleanup entry address.
// Same unwind transitions as frame 0x100079c4; no separate method ownership is assigned.
const NativeCxxUnwindEntry unboundUnwindMap2[2] = {
    {.previousState = -1, .cleanup = &UnwindDemolitionsConstructorBase},
    {.previousState = 0x00000000, .cleanup = &UnwindDemolitionsConstructorBlockClass},
};

// R6Weapons.dll data @ 10007998 : native FuncInfo with no bound dispatcher
// Words: magic, unwind-state count/map, zero try count/map and two zero tail words.
// Same unwind transitions as frame 0x100079c4; no separate method ownership is assigned.
const NativeCxxFramePrefix unboundFuncInfo2 = {
    .magic = 0x19930520,
    .unwindCount = 0x00000002,
    .unwindMap = &unboundUnwindMap2,
    .tryCount = 0x00000000,
    .tryMap = 0x00000000,
    .ipCount = 0x00000000,
    .ipMap = 0x00000000,
};

// R6Weapons.dll data @ 100079e0 : native UnwindMap with no bound dispatcher
// Pairs: signed predecessor state, cleanup entry address.
// Same unwind transitions as frame 0x10007a0c; no separate method ownership is assigned.
const NativeCxxUnwindEntry unboundUnwindMap3[1] = {
    {.previousState = -1, .cleanup = &UnwindSharedGadgetBase},
};

// R6Weapons.dll data @ 100079e8 : native FuncInfo with no bound dispatcher
// Words: magic, unwind-state count/map, zero try count/map and two zero tail words.
// Same unwind transitions as frame 0x10007a0c; no separate method ownership is assigned.
const NativeCxxFramePrefix unboundFuncInfo3 = {
    .magic = 0x19930520,
    .unwindCount = 0x00000001,
    .unwindMap = &unboundUnwindMap3,
    .tryCount = 0x00000000,
    .tryMap = 0x00000000,
    .ipCount = 0x00000000,
    .ipMap = 0x00000000,
};

// R6Weapons.dll data @ 10007a64 : native UnwindMap with no bound dispatcher
// Pairs: signed predecessor state, cleanup entry address.
// Same unwind transitions as frame 0x10007ab0; no separate method ownership is assigned.
const NativeCxxUnwindEntry unboundUnwindMap4[3] = {
    {.previousState = -1, .cleanup = &UnwindBulletConstructorBase},
    {.previousState = 0x00000000, .cleanup = &UnwindBulletConstructorAmmoName},
    {.previousState = 0x00000001, .cleanup = &UnwindBulletConstructorAmmoType},
};

// R6Weapons.dll data @ 10007a7c : native FuncInfo with no bound dispatcher
// Words: magic, unwind-state count/map, zero try count/map and two zero tail words.
// Same unwind transitions as frame 0x10007ab0; no separate method ownership is assigned.
const NativeCxxFramePrefix unboundFuncInfo4 = {
    .magic = 0x19930520,
    .unwindCount = 0x00000003,
    .unwindMap = &unboundUnwindMap4,
    .tryCount = 0x00000000,
    .tryMap = 0x00000000,
    .ipCount = 0x00000000,
    .ipMap = 0x00000000,
};

// R6Weapons.dll data @ 10007af0 : native UnwindMap with no bound dispatcher
// Pairs: signed predecessor state, cleanup entry address.
// Same unwind transitions as frame 0x10007b48; no separate method ownership is assigned.
const NativeCxxUnwindEntry unboundUnwindMap5[1] = {
    {.previousState = -1, .cleanup = &UnwindSharedActorBase},
};

// R6Weapons.dll data @ 10007af8 : native FuncInfo with no bound dispatcher
// Words: magic, unwind-state count/map, zero try count/map and two zero tail words.
// Same unwind transitions as frame 0x10007b48; no separate method ownership is assigned.
const NativeCxxFramePrefix unboundFuncInfo5 = {
    .magic = 0x19930520,
    .unwindCount = 0x00000001,
    .unwindMap = &unboundUnwindMap5,
    .tryCount = 0x00000000,
    .tryMap = 0x00000000,
    .ipCount = 0x00000000,
    .ipMap = 0x00000000,
};

// R6Weapons.dll data @ 10007b64 : native UnwindMap with no bound dispatcher
// Pairs: signed predecessor state, cleanup entry address.
// Same unwind transitions as frame 0x10007b48; no separate method ownership is assigned.
const NativeCxxUnwindEntry unboundUnwindMap6[1] = {
    {.previousState = -1, .cleanup = &UnwindSharedActorBase},
};

// R6Weapons.dll data @ 10007b6c : native FuncInfo with no bound dispatcher
// Words: magic, unwind-state count/map, zero try count/map and two zero tail words.
// Same unwind transitions as frame 0x10007b48; no separate method ownership is assigned.
const NativeCxxFramePrefix unboundFuncInfo6 = {
    .magic = 0x19930520,
    .unwindCount = 0x00000001,
    .unwindMap = &unboundUnwindMap6,
    .tryCount = 0x00000000,
    .tryMap = 0x00000000,
    .ipCount = 0x00000000,
    .ipMap = 0x00000000,
};

// R6Weapons.dll data @ 100062b0 : UTF-16 unwind format
const char16_t unwindContextFormat[] = u"%s";

// R6Weapons.dll data @ 100077f0 : void-pointer catch conversion
// Words: properties, type descriptor, PMD (member/vbtable/vbase displacement), size, copy helper.
const NativeCatchableType voidPointerCatchableType = {
    .properties = 1,
    .typeDescriptor = &voidPointerTypeDescriptor,
    .adjustment = {.memberDisplacement = 0, .vbtableDisplacement = -1, .displacementInVbtable = 0},
    .valueSize = 4,
    .copyFunction = 0,
};

// R6Weapons.dll data @ 1000780c : unsigned-short-pointer catch conversion
// Words: properties, type descriptor, PMD (member/vbtable/vbase displacement), size, copy helper.
const NativeCatchableType unsignedShortPointerCatchableType = {
    .properties = 1,
    .typeDescriptor = &unsignedShortPointerTypeDescriptor,
    .adjustment = {.memberDisplacement = 0, .vbtableDisplacement = -1, .displacementInVbtable = 0},
    .valueSize = 4,
    .copyFunction = 0,
};

// R6Weapons.dll data @ 10007828 : unsigned-short-pointer catch alternatives
// Words: count, exact unsigned-short-pointer conversion, void-pointer conversion.
const NativePointerCatchableTypes unsignedShortPointerCatchableTypes = {
    .count = 2,
    .types = {&unsignedShortPointerCatchableType, &voidPointerCatchableType},
};

// R6Weapons.dll data @ 10007834 : unsigned-short-pointer throw metadata
// Words: attributes, unwind helper, forward-compatibility helper, catchable-type-array address.
const NativeThrowInfo unsignedShortPointerThrowInfo = {
    .attributes = 0,
    .destructor = 0,
    .compatibilityHook = 0,
    .catchableTypes = &unsignedShortPointerCatchableTypes,
};

// R6Weapons.dll data @ 1000c078 : void-pointer exception type descriptor
// Words: native descriptor vptr, mutable spare word, ASCII .PAX plus NUL and padding.
NativePointerTypeDescriptor voidPointerTypeDescriptor = {
    .virtualTable = &typeInfoVtable,
    .spare = 0,
    .typeName = ".PAX",
};

// R6Weapons.dll data @ 1000c088 : unsigned-short-pointer exception type descriptor
// Words: native descriptor vptr, mutable spare word, ASCII .PAG plus NUL and padding.
NativePointerTypeDescriptor unsignedShortPointerTypeDescriptor = {
    .virtualTable = &typeInfoVtable,
    .spare = 0,
    .typeName = ".PAG",
};

// R6Weapons.dll data @ 10007770 : SafeSEH handler RVA array named by the PE load configuration
// These sorted RVAs identify the SEH dispatcher and 27 reviewed C++ dispatchers; entries are not relocated pointers.
const uint safeExceptionHandlerRVAs[28] = {
    0x00005388, 0x00005430, 0x00005467, 0x00005498, 0x000054b8, 0x000054f6, 0x00005517,
    0x00005538, 0x00005586, 0x000055b7, 0x000055d8, 0x00005608, 0x00005629, 0x00005640,
    0x00005650, 0x00005660, 0x00005670, 0x00005680, 0x00005690, 0x000056a0, 0x000056b0,
    0x000056c0, 0x000056d0, 0x000056e0, 0x000056f0, 0x00005700, 0x00005710, 0x00005720,
};

// R6Weapons.dll @ 1000508a : tail-transfer the current C++ exception frame to the imported dispatcher
// Leaves every register and stack word unchanged for the CRT frame handler.
__declspec(naked) void __CxxFrameHandler(void) {
  __asm {
    jmp dword ptr ds:[crtCxxFrameHandlerImport]
  }
}

// R6Weapons.dll @ 10005090 : tail-transfer the supplied exception object and metadata to the imported throw helper
// Parameter names expose the incoming stack words; the naked thunk adds no frame, cleanup or return path.
__declspec(naked) __declspec(noreturn) void _CxxThrowException(void *exceptionObject, ThrowInfo *throwInfo) {
  __asm {
    jmp dword ptr ds:[crtCxxThrowExceptionImport]
  }
}

// R6Weapons.dll @ 10005334 : tail-transfer to the imported termination routine
// Preserves the incoming stack and registers; the imported target does not return.
__declspec(naked) __declspec(noreturn) void __cdecl terminate(void) {
  __asm {
    jmp dword ptr ds:[crtTerminateImport]
  }
}

// R6Weapons.dll @ 1000533c : Installs the caller's SEH record and saves its frame and nonvolatile registers.
__declspec(naked) void __SEH_prolog(void) {
  __asm {
    push offset DispatchStructuredException // Local thunk to imported _except_handler3.
    mov eax,fs:[0]
    push eax
    mov eax,dword ptr [esp+0x10]
    mov dword ptr [esp+0x10],ebp
    lea ebp,[esp+0x10]
    sub esp,eax
    push ebx
    push esi
    push edi
    mov eax,dword ptr [ebp-0x8]
    mov dword ptr [ebp-0x18],esp
    push eax
    mov eax,dword ptr [ebp-0x4]
    mov dword ptr [ebp-0x4],0xffffffff
    mov dword ptr [ebp-0x8],eax
    lea eax,[ebp-0x10]
    mov fs:[0],eax
    ret
  }
}

// R6Weapons.dll @ 10005377 : Restores the enclosing SEH chain, saved registers, frame, and continuation.
__declspec(naked) void __SEH_epilog(void) {
  __asm {
    mov ecx,dword ptr [ebp-0x10]
    mov dword ptr fs:[0],ecx
    pop ecx
    pop edi
    pop esi
    pop ebx
    leave
    push ecx
    ret
  }
}

// R6Weapons.dll @ 10005388 : tail-transfer the active SEH frame to imported _except_handler3
// This register/stack view is installed by __SEH_prolog; it does not invent a normal C++ call signature.
__declspec(naked) void DispatchStructuredException(void) {
  __asm {
    jmp dword ptr ds:[crtExceptHandlerImport]
  }
}

// R6Weapons.dll @ 1000538e : tail-transfer callback registration with the supplied mutable table bounds
// Preserves stack arguments and the imported __dllonexit result without a recursive call.
__declspec(naked) _onexit_t __cdecl __dllonexit(_onexit_t callback, _onexit_t **begin, _onexit_t **end) {
  __asm {
    jmp dword ptr ds:[crtDllOnExitImport]
  }
}

// R6Weapons.dll @ 10005394 : tail-transfer the initializer callback range to imported _initterm
// Preserves both cdecl range arguments and the incoming stack unchanged.
__declspec(naked) void __cdecl initterm(void(__cdecl **begin)(void), void(__cdecl **end)(void)) {
  __asm {
    jmp dword ptr ds:[crtInitTermImport]
  }
}

// R6Weapons.dll @ 10005422 : tail-transfer exception code and pointers to the imported CRT exception filter
// Returns the imported disposition directly without adding a recursive call or argument cleanup.
__declspec(naked) int __cdecl __CppXcptFilter(ulong exceptionCode, EXCEPTION_POINTERS *exceptionPointers) {
  __asm {
    jmp dword ptr ds:[crtCppExceptionFilterImport]
  }
}
