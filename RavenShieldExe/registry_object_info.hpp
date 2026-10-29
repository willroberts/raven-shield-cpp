#pragma once

class FString;

// Native Core record: five owned 12-byte strings, no vptr, 60-byte stride; requires the external FString declaration.
// Field spellings follow UE2; selected Core parser keys and constructor/copy/destructor accesses corroborate the roles.
class __declspec(dllimport) FRegistryObjectInfo
{
public:
  FString Object;      // +00, parsed from Name=; full registered object path.
  FString Class;       // +0c, parsed from Class=.
  FString MetaClass;   // +18, parsed from MetaClass=.
  FString Description; // +24, parsed from Description=.
  FString Autodetect;  // +30, parsed from Autodetect=; renderer probe filename.
  FRegistryObjectInfo();
  FRegistryObjectInfo(const FRegistryObjectInfo &other);
  ~FRegistryObjectInfo() noexcept(false);
  FRegistryObjectInfo &operator=(const FRegistryObjectInfo &other);
};
