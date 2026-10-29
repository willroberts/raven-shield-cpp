using CrtInitializer = void(__cdecl *)(void);

// R6Weapons.dll data @ 1000c000 : ordered CRT initialization range, ending before 0x1000c058
// The leading null slot and following twenty-one callbacks are consumed by imported _initterm.
CrtInitializer crtInitializers[22] = {
    nullptr, RegisterHeartbeatScriptNative, RegisterBulletSurfaceScriptNative, InitializeAR6BulletClassMetadata,
    InitializeAR6BulletAutoClass, InitializeAR6GrenadeClassMetadata, InitializeAR6GrenadeAutoClass,
    InitializeAR6WeaponsClassMetadata, InitializeAR6WeaponsAutoClass, InitializeAR6HBSGadgetClassMetadata,
    InitializeAR6HBSGadgetAutoClass, InitializeAR6GadgetClassMetadata, InitializeAR6GadgetAutoClass,
    InitializeAR6GrenadeWeaponClassMetadata, InitializeAR6GrenadeWeaponAutoClass,
    InitializeAR6DemolitionsGadgetClassMetadata, InitializeAR6DemolitionsGadgetAutoClass,
    InitializeAR6ReticuleClassMetadata, InitializeAR6ReticuleAutoClass, InitializeAR6SmokeCloudClassMetadata,
    InitializeAR6SmokeCloudAutoClass, InitializeR6WeaponsEventNameStorage,
};

// R6Weapons.dll data @ 1000c058 : zero word at the exclusive end of the CRT initializer range
// _initterm receives this address as its upper bound and does not execute this word.
const uint crtInitializerEndWord = 0;

using DllNotificationHook = int(__stdcall *)(void *, uint, void *);

// R6Weapons.dll data @ 1000cb0c : latest module handle supplied to the module callback
void *dllModuleHandle = nullptr;
// R6Weapons.dll data @ 1000ee78 : signed successful CRT attachment count
int crtAttachCount = 0;
// R6Weapons.dll data @ 1000ee7c : snapshot of imported _adjust_fdiv
uint adjustFdivSnapshot = 0;
// R6Weapons.dll data @ 1000ee80 : optional raw DLL notification hook
DllNotificationHook rawDllNotificationHook = nullptr;
// R6Weapons.dll data @ 1000ee84 : mutable end of the DLL exit callback table
_onexit_t *exitCallbacksEnd = nullptr;
// R6Weapons.dll data @ 1000ee88 : mutable base of the DLL exit callback table, or the -1 registration sentinel
_onexit_t *exitCallbacksBegin = nullptr;

// Aliases for existing PE32 IAT cells; each holds one four-byte imported address.
// R6Weapons.dll import @ 10006254 : MSVCR71.dll _onexit
extern uint crtOnExitImport;
// R6Weapons.dll label @ 1000530c : embedded exception entry represented by the parent body
extern NativeCodeLabel dllCrtEntryExceptionFilter;
// R6Weapons.dll label @ 1000531d : embedded exception entry represented by the parent body
extern NativeCodeLabel dllCrtEntryExceptionHandler;

// R6Weapons.dll data @ 100076a8 : DLL CRT entry exception-filter scope
// Words: signed enclosing scope (-1), filter entry (zero means finally), handler/finally entry.
const NativeSehScope dllCrtEntryScope = {
    .enclosingState = -1,
    .filter = &dllCrtEntryExceptionFilter,
    .handler = &dllCrtEntryExceptionHandler,
};

// R6Weapons.dll @ 10003e70 : remember the supplied module handle and accept every DLL notification
// Stores the handle on every call; reason and reserved do not affect the full-width success result.
int __stdcall _DllMain_12(void *moduleHandle, uint unusedReason, void *unusedReserved) {
  dllModuleHandle = moduleHandle;
  return 1;
}

// R6Weapons.dll @ 10005154 : register an exit callback through the selected CRT callback table
// Base -1 tail-jumps to imported _onexit; other bases pass the mutable DLL table bounds to __dllonexit.
__declspec(naked) _onexit_t __cdecl __onexit(_onexit_t callback) {
  __asm {
    cmp dword ptr [exitCallbacksBegin], 0xffffffff
    jne registerInDllTable
    jmp dword ptr ds:[crtOnExitImport]
  registerInDllTable:
    push offset exitCallbacksEnd
    push offset exitCallbacksBegin
    push dword ptr [esp+0x0c]
    call __dllonexit
    add esp, 0x0c
    ret
  }
}

// R6Weapons.dll @ 1000517a : register a void exit callback and return zero for nonnull registration
// Forwards the callback unchanged; null registration maps to -1 without a separate callback guard.
int __cdecl _atexit(void(__cdecl *callback)(void)) {
  _onexit_t registeredCallback = __onexit((_onexit_t)callback);
  return registeredCallback != nullptr ? 0 : -1;
}

// R6Weapons.dll @ 1000518c : initialize or tear down the DLL CRT callback state for the notification
// Allocates the exit table on attach and visits it backward on detach, reloading its base after every callback.
int __stdcall __CRT_INIT_12(void *unusedModuleHandle, uint reason, void *unusedReserved) {
  using ExitCallback = _onexit_t;
  if (reason == 0) {
    if (crtAttachCount <= 0) {
      return 0;
    }
    --crtAttachCount;
  }
  adjustFdivSnapshot = *(uint *)_adjust_fdiv_exref;
  if (reason == 1) {
    ExitCallback *allocatedTable = (ExitCallback *)malloc(0x80);
    exitCallbacksBegin = allocatedTable;
    if (allocatedTable == nullptr) {
      return 0;
    }
    *allocatedTable = nullptr;
    exitCallbacksEnd = exitCallbacksBegin;
    __RTC_Initialize();
    _atexit(RunCrtTerminationCallbacks);
    initterm(crtInitializers, crtInitializers + 22);
    crtAttachCount = (int)((uint)crtAttachCount + 1);
  } else if (reason == 0) {
    ExitCallback *tableBase = (ExitCallback *)exitCallbacksBegin;
    if (tableBase != nullptr) {
      for (;;) {
        exitCallbacksEnd = (ExitCallback *)((uint)exitCallbacksEnd - 4);
        if ((uint)exitCallbacksEnd < (uint)tableBase)
          break;
        ExitCallback callback = *((ExitCallback *)exitCallbacksEnd);
        if (callback != nullptr) {
          callback();
          tableBase = (ExitCallback *)exitCallbacksBegin;
        }
      }
      free(tableBase);
      exitCallbacksBegin = nullptr;
    }
  }
  return 1;
}

// R6Weapons.dll @ 1000524a : dispatch DLL notifications through raw hook, CRT state and module callback
// Attach runs hook/CRT before the module; detach runs module/CRT before a fresh hook read, all under the CRT SEH
// filter.
int __stdcall DllCrtEntry(void *moduleHandle, uint reason, void *reserved) {
  using NotificationHook = int(__stdcall *)(void *, uint, void *);
  int notificationResult = 1;
  __try {
    if (reason == 0 && crtAttachCount == 0) {
      return 0;
    }
    if (reason == 1 || reason == 2) {
      NotificationHook rawHook = (NotificationHook)rawDllNotificationHook;
      if (rawHook != nullptr) {
        notificationResult = rawHook(moduleHandle, reason, reserved);
      }
      if (notificationResult == 0) {
        return 0;
      }
      notificationResult = __CRT_INIT_12(moduleHandle, reason, reserved);
      if (notificationResult == 0) {
        return 0;
      }
    }
    notificationResult = _DllMain_12(moduleHandle, reason, reserved);
    if (reason == 1 && notificationResult == 0) {
      __CRT_INIT_12(moduleHandle, 0, reserved);
    }
    if (reason == 0 || reason == 3) {
      if (__CRT_INIT_12(moduleHandle, reason, reserved) == 0) {
        notificationResult = 0;
      }
      if (notificationResult != 0) {
        NotificationHook rawHook = (NotificationHook)rawDllNotificationHook;
        if (rawHook != nullptr) {
          notificationResult = rawHook(moduleHandle, reason, reserved);
        }
      }
    }
    return notificationResult;
  } __except (__CppXcptFilter(GetExceptionCode(), GetExceptionInformation())) {
    return 0;
  }
}
