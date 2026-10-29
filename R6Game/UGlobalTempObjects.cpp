#include "native_addresses.h"
#include "exception_registration.h"
#include "module_data.h"

// Native exception metadata uses preferred-VA DWORD snapshots; pointer cells retain PE HIGHLOW relocations.

// R6Game.dll data @ 1001b928 : native C++ unwind-state transitions
const unsigned int UGlobalTempObjects_AddGlobalObjectUnwindMap[4] = {
    0xffffffff, 0x0, // State 0: previous state, cleanup action.
    0xffffffff, 0x0, // State 1: previous state, cleanup action.
};

// R6Game.dll data @ 1001b938 : native typed-pointer and catch-all handler pair
const unsigned int UGlobalTempObjects_AddGlobalObjectCatchHandlers[8] = {
    0x0, R6GameAddresses::UnsignedShortPointerTypeDescriptor, 0xffffffe8, R6GameAddresses::UGlobalTempObjects_AddGlobalObjectCatchPointer, // Typed: adjectives, type, signed frame offset, action.
    0x0, 0x0, 0x0, R6GameAddresses::UGlobalTempObjects_AddGlobalObjectCatchContext, // Catch-all: adjectives, type, signed frame offset, action.
};

// R6Game.dll data @ 1001b958 : native C++ try-block ranges
const unsigned int UGlobalTempObjects_AddGlobalObjectTryMap[5] = {
    0x0, 0x0, 0x1, 0x2, R6GameAddresses::UGlobalTempObjects_AddGlobalObjectCatchHandlers, // Try 0: low/high/catch-high state, count, handler array.
};

// R6Game.dll data @ 1001b96c : native C++ exception function descriptor
const unsigned int UGlobalTempObjects_AddGlobalObjectExceptionInfo[7] = {
    0x19930520, 0x2, R6GameAddresses::UGlobalTempObjects_AddGlobalObjectUnwindMap, // Magic, state count, unwind map.
    0x1, R6GameAddresses::UGlobalTempObjects_AddGlobalObjectTryMap, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll @ 1000ce20 : register the address of a global object pointer in temporary-object storage
void __thiscall UGlobalTempObjects::AddGlobalObject(UGlobalTempObjects* this, UObject** objectStorage)
{
  NativeCppExceptionRegistration exceptionRegistration;
  exceptionRegistration.state = -1;
  exceptionRegistration.handlerAddress = (uint)&GlobalTempObjectsAddExceptionHandler;
  exceptionRegistration.previousAddress = __readfsdword(0);
  __writefsdword(0, (uint)&exceptionRegistration);
  // Native saves funclet ESP at EBP-0x10 after saving EBX/ESI/EDI.
  FArray* objectReferences = (FArray*)((byte*)this + 0x2c);
  exceptionRegistration.state = 0;
  int addedIndex = FArray::Add(objectReferences, 1, 4);
  UObject*** referenceData = *(UObject****)objectReferences;
  // Native restores EDI before this unchecked DWORD store.
  *(UObject***)((uint)referenceData + (uint)addedIndex * 4U) = objectStorage;
  __writefsdword(0, exceptionRegistration.previousAddress);
}

// R6Game.dll @ 1000ce72 : rethrow global-reference registration's caught four-byte value
__declspec(naked) void UGlobalTempObjects_AddGlobalObjectCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x18]
        push offset UnsignedShortPointerThrowInfo
        lea ecx,[ebp-0x14]
        push ecx
        mov dword ptr [ebp-0x14],eax
        call _CxxThrowException
    }
}

// R6Game.dll @ 1000ce86 : report registration context and rethrow the active exception
__declspec(naked) void UGlobalTempObjects_AddGlobalObjectCatchContext(void)
{
    __asm {
        push R6GameAddresses::UGlobalTempObjects_AddGlobalObjectExceptionContext // L"UGlobalTempObjects::AddGlobalObject"
        push R6GameAddresses::ExceptionContextFormat // L"%s"
        call dword ptr ds:R6GameAddresses::Core_appUnwindfSlot // appUnwindf.
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Game.dll @ 100141a0 : dispatch global-reference registration's exception states
__declspec(naked) void GlobalTempObjectsAddExceptionHandler(void)
{
  __asm { mov eax, offset UGlobalTempObjects_AddGlobalObjectExceptionInfo }
  __asm { jmp R6GameAddresses::CxxFrameHandler }
}
