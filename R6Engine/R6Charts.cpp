// Native helper declarations match their canonical definitions.
__declspec(naked) long long TruncateX87ToSigned64();
// R6Engine.dll @ 1003f6c0 : R6Charts::R6Charts
// Returns the receiver without initializing instance storage; the charts themselves are static data.
// Native ABI leaf returns ECX verbatim without object access or an implicit initialization sequence.
R6Charts* __thiscall R6Charts::R6Charts(R6Charts* this)
{
    return this;
}

// R6Engine.dll @ 1003f6d0 : R6Charts::operator=
// Returns the receiver without reading the source argument or changing instance storage.
// Native ABI leaf returns ECX verbatim without dereferencing either receiver or source word.
R6Charts* __thiscall R6Charts::operator=(R6Charts* this, const R6Charts* source)
{
    return this;
}

// R6Engine.dll @ 1003f6e0 : R6Charts::GetKillTable
// Selects one of three chart rows for body-part codes zero through four, or returns null.
stResultTable* __thiscall R6Charts::GetKillTable(eBodyPart bodyPart)
{
    switch ((uint)bodyPart) {
    case 0:
        return (stResultTable*)&R6Charts::m_stKillChart;
    case 1:
    case 2:
        return (stResultTable*)((byte*)&R6Charts::m_stKillChart + 0x10);
    case 3:
    case 4:
        return (stResultTable*)((byte*)&R6Charts::m_stKillChart + 0x20);
    default:
        return nullptr;
    }
}

// R6Engine.dll @ 1003f730 : R6Charts::GetStunTable
// Selects one of three chart rows for body-part codes zero through four, or returns null.
stResultTable* __thiscall R6Charts::GetStunTable(eBodyPart bodyPart)
{
    switch ((uint)bodyPart) {
    case 0:
        return (stResultTable*)&R6Charts::m_stStunChart;
    case 1:
    case 2:
        return (stResultTable*)((byte*)&R6Charts::m_stStunChart + 0x10);
    case 3:
    case 4:
        return (stResultTable*)((byte*)&R6Charts::m_stStunChart + 0x20);
    default:
        return nullptr;
    }
}

// R6Engine.dll @ 1003f780 : compute a table-adjusted character value and cap its upper result
// Subtracts body-part/armor penetration scaled for the hit angle, truncates via x87 and caps only results above 5000.
int __thiscall R6Charts::BulletGoesThroughCharacter(int damage, int bodyPart, int armorType, int obliqueHit)
{
  (void)this;
  uint firstTableIndex = (uint)armorType + (uint)bodyPart * 3;
  uint secondTableIndex = (uint)obliqueHit + (uint)bodyPart * 2;
  int tableValue = *(int *)(((uint)&R6Charts::m_iHumanPenetrationTresholds) + firstTableIndex * 4);
  float tableScale = *(float *)(((uint)&R6Charts::m_fHumanSidePenetrationFactors) + secondTableIndex * 4);
  float10 scaledTableValue = (float10)tableValue * (float10)tableScale;
  float10 adjustedValue = (float10)damage - scaledTableValue;

  // The native truncation helper consumes ST0 and returns the corrected signed 64-bit value in EDX:EAX.
  __asm { fld adjustedValue }
  long long truncatedValue = TruncateX87ToSigned64();
  int result = (int)truncatedValue;
  if (result > 5000)
    result = 5000;
  return result;
}
