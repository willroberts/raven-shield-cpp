#include "native_addresses.h"

// Native exception metadata uses preferred-VA DWORD snapshots; pointer cells retain PE HIGHLOW relocations.

// R6Game.dll data @ 1001a074 : native C++ unwind-state transitions
const unsigned int FileManagerDestructionUnwindMap[2] = {
    0xffffffff, R6GameAddresses::FileManagerDestructionUnwind, // State 0: previous state, cleanup action.
};

// R6Game.dll data @ 1001a07c : native C++ exception function descriptor
const unsigned int FileManagerDestructionExceptionInfo[7] = {
    0x19930520, 0x1, R6GameAddresses::FileManagerDestructionUnwindMap, // Magic, state count, unwind map.
    0x0, 0x0, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 1001a72c : native C++ unwind-state transitions
const unsigned int SoundVolumeDerivedDestructorUnwindMap[2] = {
    0xffffffff, R6GameAddresses::SoundVolumeDerivedDestructorUnwind, // State 0: previous state, cleanup action.
};

// R6Game.dll data @ 1001a734 : native C++ exception function descriptor
const unsigned int SoundVolumeDerivedDestructorExceptionInfo[7] = {
    0x19930520, 0x1, R6GameAddresses::SoundVolumeDerivedDestructorUnwindMap, // Magic, state count, unwind map.
    0x0, 0x0, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll @ 10001940 : return supplied memory for the shared class placement-allocation overloads
/* public: static void * __cdecl AR6ActionPoint::operator new(unsigned int,enum EInternal *) */
void * __cdecl AR6ActionPoint::operator_new(uint allocationSize,EInternal *objectMemory)
{
                    /* 0x1940  50  ??2AR6ActionPoint@@SAPAXIPAW4EInternal@@@Z
                       0x1940  52  ??2AR6GameInfo@@SAPAXIPAW4EInternal@@@Z
                       0x1940  54  ??2AR6HUD@@SAPAXIPAW4EInternal@@@Z
                       0x1940  56  ??2AR6InstructionSoundVolume@@SAPAXIPAW4EInternal@@@Z
                       0x1940  58  ??2AR6MultiPlayerGameInfo@@SAPAXIPAW4EInternal@@@Z
                       0x1940  60  ??2AR6PlanningCtrl@@SAPAXIPAW4EInternal@@@Z
                       0x1940  62  ??2AR6SoundVolume@@SAPAXIPAW4EInternal@@@Z
                       0x1940  64  ??2AR6WaterVolume@@SAPAXIPAW4EInternal@@@Z
                       0x1940  66  ??2UR6FileManagerCampaign@@SAPAXIPAW4EInternal@@@Z
                       0x1940  68  ??2UR6FileManagerPlanning@@SAPAXIPAW4EInternal@@@Z
                       0x1940  70  ??2UR6GameManager@@SAPAXIPAW4EInternal@@@Z
                       0x1940  72  ??2UR6MissionRoster@@SAPAXIPAW4EInternal@@@Z
                       0x1940  74  ??2UR6Operative@@SAPAXIPAW4EInternal@@@Z
                       0x1940  76  ??2UR6PlanningInfo@@SAPAXIPAW4EInternal@@@Z
                       0x1940  78  ??2UR6PlayerCampaign@@SAPAXIPAW4EInternal@@@Z
                       0x1940  80  ??2UR6PlayerCustomMission@@SAPAXIPAW4EInternal@@@Z */
  // All sixteen class exports share this body; allocationSize is ignored and no constructor runs.
  return objectMemory;
}

// R6Game.dll @ 10004620 : assign inherited state and members
// Shared SoundVolume/WaterVolume assignment: copies the volume base, sound-slot byte and two sound arrays.
AR6SoundVolume * __thiscall AR6SoundVolume::operator=(AR6SoundVolume *this, const AR6SoundVolume *source)
{
  AVolume::operator=((AVolume *)this, (const AVolume *)source);
  this->m_eSoundSlot = source->m_eSoundSlot; // +0x40c.
  AssignFourByteFArray((FArray *)&this->m_EntrySound, (const FArray *)&source->m_EntrySound);
  AssignFourByteFArray((FArray *)&this->m_ExitSound, (const FArray *)&source->m_ExitSound);
  return this;
}

// R6Game.dll @ 10013570 : destroy the saved file-manager base if derived shutdown unwinds
__declspec(naked) void FileManagerDestructionUnwind(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp dword ptr ds:R6GameAddresses::Engine_UR6FileManager_DestructorSlot // UR6FileManager destructor.
    }
}

// R6Game.dll @ 100136a0 : destroy the sound-volume base if derived conditional shutdown unwinds
__declspec(naked) void SoundVolumeDerivedDestructorUnwind(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp R6GameAddresses::AR6SoundVolume_Destruct // ~AR6SoundVolume.
    }
}

// R6Game.dll @ 100136a8 : dispatch shared derived-sound-volume destructor cleanup
__declspec(naked) void SoundVolumeDerivedDestructorExceptionHandler(void)
{
  __asm { mov eax, offset SoundVolumeDerivedDestructorExceptionInfo }
  __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// R6Game.dll @ 10013579 : dispatch native C++ cleanup and catch states through FuncInfo 0x1001a07c
__declspec(naked) void FileManagerDestructionExceptionDispatcher(void)
{
    __asm { mov eax, offset FileManagerDestructionExceptionInfo }
    __asm { jmp R6GameAddresses::CxxFrameHandler }
}
