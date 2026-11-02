#include "native_shared_entries.hpp"

// Native helper declarations match their canonical definitions.
FArray* __thiscall CopyConstructRecords16(FArray* destination, const FArray* source);

// Native44-byte record associated with matching1.60 stZDR metadata; C++ type/helper spellings are descriptive.
// R6Engine.dll @ 10010cd0 : DestroyRecordArrayAt14
// Tail-destroys the16-byte-record array at record+0x14 without adding a frame or member cleanup.
__declspec(naked) void __thiscall DestroyRecordArrayAt14(void* record)
{
    __asm {
        add ecx,0x14
        jmp DestroySixteenByteArrayStorage
    }
}

// R6Engine.dll @ 10013910 : CopyConstructZDR
// Copies a ZDR record's scalar fields and constructs its sound-list array.
void* __thiscall CopyConstructZDR(void* destination, const void* source)
{
    byte* destinationRecord = (byte*)destination;
    const byte* sourceRecord = (const byte*)source;
    destinationRecord[0] = sourceRecord[0]; // m_eZDRType.
    destinationRecord[1] = sourceRecord[1]; // m_eZDRStat; padding at +2/+3 remains untouched.
    *(uint*)(destinationRecord + 4) = *(const uint*)(sourceRecord + 4); // m_fZDRRadius.
    *(uint*)(destinationRecord + 8) = *(const uint*)(sourceRecord + 8); // m_vZDRLocation.X.
    *(uint*)(destinationRecord + 12) = *(const uint*)(sourceRecord + 12);
    *(uint*)(destinationRecord + 16) = *(const uint*)(sourceRecord + 16);
    CopyConstructRecords16((FArray*)(destinationRecord + 0x14), (const FArray*)(sourceRecord + 0x14));
    *(uint*)(destinationRecord + 0x20) = *(const uint*)(sourceRecord + 0x20); // m_iZDRDamageStat.
    *(uint*)(destinationRecord + 0x24) = *(const uint*)(sourceRecord + 0x24); // m_fZDRImpactInterval.
    *(uint*)(destinationRecord + 0x28) = *(const uint*)(sourceRecord + 0x28); // m_fZDRLastImpactTime.
    return destination;
}
