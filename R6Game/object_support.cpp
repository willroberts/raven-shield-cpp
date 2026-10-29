#include "import_bindings.h"

// R6Game.dll @ 1000b650 : construct an object constrained to the selected FinalBlend class
UFinalBlend* __cdecl ConstructCheckedFinalBlend(UClass* classToConstruct, UObject* outer, FName name, uint objectFlags)
{
  UClass* classCursor = classToConstruct;
  if (classCursor != nullptr) {
    UClass* expectedClass = (UClass*)ImportedUFinalBlendClass;
    while (classCursor != nullptr && classCursor != expectedClass)
      classCursor = *(UClass**)((byte*)classCursor + 0x2c);
  }
  if (classCursor == nullptr)
    appFailAssert("Class->IsChildOf(T::StaticClass())", "d:\\ravenshield\\412\\core\\inc\\UnObjBas.h", 0x476);
  if (outer == (UObject*)0xffffffff)
    outer = (UObject*)UObject::GetTransientPackage();
  FOutputDevice* error = *(FOutputDevice**)ImportedGErrorAddress;
  return (UFinalBlend*)UObject::StaticConstructObject(classToConstruct, outer, name, objectFlags, nullptr, error, 0);
}

// R6Game.dll @ 1000b6c0 : return the object address when its class chain matches AR6TeamMemberReplicationInfo
int __cdecl CastToAR6TeamMemberReplicationInfo(int objectAddress)
{
  if (objectAddress == 0)
    return 0;
  UClass* classCursor = *(UClass**)(objectAddress + 0x24);
  UClass* expectedClass = (UClass*)ImportedAR6TeamMemberReplicationInfoClass;
  while (classCursor != nullptr && classCursor != expectedClass)
    classCursor = *(UClass**)((byte*)classCursor + 0x2c);
  return classCursor == expectedClass ? objectAddress : 0;
}

// R6Game.dll @ 1000b6f0 : return the object address when its class chain matches AR6Weapons
int __cdecl CastToAR6Weapons(int objectAddress)
{
  if (objectAddress == 0)
    return 0;
  UClass* classCursor = *(UClass**)(objectAddress + 0x24);
  UClass* expectedClass = (UClass*)ImportedAR6WeaponsClass;
  while (classCursor != nullptr && classCursor != expectedClass)
    classCursor = *(UClass**)((byte*)classCursor + 0x2c);
  return classCursor == expectedClass ? objectAddress : 0;
}

// R6Game.dll @ 1000b720 : return the object address when its class chain matches UMaterial
int __cdecl CastToUMaterial(int objectAddress)
{
  if (objectAddress == 0)
    return 0;
  UClass* classCursor = *(UClass**)(objectAddress + 0x24);
  UClass* expectedClass = (UClass*)ImportedUMaterialClass;
  while (classCursor != nullptr && classCursor != expectedClass)
    classCursor = *(UClass**)((byte*)classCursor + 0x2c);
  return classCursor == expectedClass ? objectAddress : 0;
}

// R6Game.dll @ 1000b750 : return the object address when its class chain matches AController
int __cdecl CastToAController(int objectAddress)
{
  if (objectAddress == 0)
    return 0;
  UClass* classCursor = *(UClass**)(objectAddress + 0x24);
  UClass* expectedClass = (UClass*)ImportedAControllerClass;
  while (classCursor != nullptr && classCursor != expectedClass)
    classCursor = *(UClass**)((byte*)classCursor + 0x2c);
  return classCursor == expectedClass ? objectAddress : 0;
}

// R6Game.dll @ 1000b780 : return the object address when its class chain matches AR6Pawn
int __cdecl CastToAR6Pawn(int objectAddress)
{
  if (objectAddress == 0)
    return 0;
  UClass* classCursor = *(UClass**)(objectAddress + 0x24);
  UClass* expectedClass = (UClass*)ImportedAR6PawnClass;
  while (classCursor != nullptr && classCursor != expectedClass)
    classCursor = *(UClass**)((byte*)classCursor + 0x2c);
  return classCursor == expectedClass ? objectAddress : 0;
}

// R6Game.dll @ 10001890 : return the object address when its class chain matches AR6PlayerController
int __cdecl CastToAR6PlayerController(int objectAddress)
{
  if (objectAddress == 0)
    return 0;
  UClass* classCursor = *(UClass**)(objectAddress + 0x24);
  UClass* expectedClass = (UClass*)ImportedAR6PlayerControllerClass;
  while (classCursor != nullptr && classCursor != expectedClass)
    classCursor = *(UClass**)((byte*)classCursor + 0x2c);
  return classCursor == expectedClass ? objectAddress : 0;
}

// R6Game.dll @ 1000b7b0 : return the object address when its class chain matches AR6RainbowAI
int __cdecl CastToAR6RainbowAI(int objectAddress)
{
  if (objectAddress == 0)
    return 0;
  UClass* classCursor = *(UClass**)(objectAddress + 0x24);
  UClass* expectedClass = (UClass*)ImportedAR6RainbowAIClass;
  while (classCursor != nullptr && classCursor != expectedClass)
    classCursor = *(UClass**)((byte*)classCursor + 0x2c);
  return classCursor == expectedClass ? objectAddress : 0;
}

// R6Game.dll @ 1000b7e0 : return the object address when its class chain matches AR6ActionPointAbstract
int __cdecl CastToAR6ActionPointAbstract(int objectAddress)
{
  if (objectAddress == 0)
    return 0;
  UClass* classCursor = *(UClass**)(objectAddress + 0x24);
  UClass* expectedClass = (UClass*)ImportedAR6ActionPointAbstractClass;
  while (classCursor != nullptr && classCursor != expectedClass)
    classCursor = *(UClass**)((byte*)classCursor + 0x2c);
  return classCursor == expectedClass ? objectAddress : 0;
}

// R6Game.dll @ 10001860 : return the object address when its class chain matches UViewport
int __cdecl CastToUViewport(int objectAddress)
{
  if (objectAddress == 0)
    return 0;
  UClass* classCursor = *(UClass**)(objectAddress + 0x24);
  UClass* expectedClass = (UClass*)ImportedUViewportClass;
  while (classCursor != nullptr && classCursor != expectedClass)
    classCursor = *(UClass**)((byte*)classCursor + 0x2c);
  return classCursor == expectedClass ? objectAddress : 0;
}

// R6Game.dll @ 100092d0 : test the actor's live location against stair volumes in its level
int __cdecl IsActorInsideStairVolume(AActor* actor)
{
    ULevel* level = *(ULevel**)((byte*)actor + 0x328); // Actor.XLevel.
    if (*(int*)((byte*)level + 0x34) <= 0)
        return 0;
    using EncompassesCall = int (__thiscall*)(AVolume*, FVector);
    EncompassesCall encompasses = *(EncompassesCall*)R6GameImports::Engine_AVolume_EncompassesSlot; // Captured once across callbacks.
    UClass* expectedClass = (UClass*)ImportedAR6StairVolumeClass;
    int entryIndex = 0;
    do {
        AVolume* candidate = (*(AVolume***)((byte*)level + 0x30))[entryIndex];
        if (candidate != nullptr) {
            UClass* classCursor = *(UClass**)((byte*)candidate + 0x24);
            while (classCursor != nullptr && classCursor != expectedClass)
                classCursor = *(UClass**)((byte*)classCursor + 0x2c);
            if (classCursor == expectedClass) { // A null expected class accepts an exhausted chain.
                FVector point = *(FVector*)((byte*)actor + 0x234); // Actor.Location, copied for each call.
                if (encompasses(candidate, point) != 0)
                    return 1;
                expectedClass = (UClass*)ImportedAR6StairVolumeClass;
            }
        }
        level = *(ULevel**)((byte*)actor + 0x328);
        int liveCount = *(int*)((byte*)level + 0x34);
        entryIndex = (int)((uint)entryIndex + 1U);
        if (entryIndex >= liveCount)
            return 0;
    } while (true);
}

// R6Game.dll @ 10011e60 : return the object if its class chain contains AR6GameReplicationInfo
// ImportedAR6GameReplicationInfoClass identifies the imported UClass at IAT 0x1001655c.
int __cdecl CastToAR6GameReplicationInfo(int object)
{
  UClass *expectedClass;
  UClass *classCursor;

  if (object != 0) {
    classCursor = *(UClass **)((byte *)object + 0x24);
    expectedClass = (UClass *)ImportedAR6GameReplicationInfoClass;
    for (; classCursor != (UClass *)0x0; classCursor = *(UClass **)((byte *)classCursor + 0x2c)) {
      if (classCursor == expectedClass) {
        return object;
      }
    }
    if (expectedClass == (UClass *)0x0) {
      return object;
    }
  }
  return 0;
}
