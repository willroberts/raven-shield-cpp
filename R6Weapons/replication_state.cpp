// Shared replication snapshots. Names describe native use; each location is a zero-initialized module-wide dword.
// R6Weapons.dll data @ 1000cb08 : previous zero-extended m_iNbBulletsInWeapon byte for weapon and gadget receive hooks
uint previousBulletCount = 0;
