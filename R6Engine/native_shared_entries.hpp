#pragma once

// Shared native helper declarations, matching the existing canonical definitions.
// Inherited-frame funclets retain their assembly contracts; no ordinary call is introduced here.

__declspec(naked) void __cdecl ActorBaseOnlyDestructionExceptionHandler(void);

__declspec(naked) void AiControllerBaseExceptionHandler(void);

__declspec(naked) void __thiscall DestroyArrayPairAt40And4c(void* record);

void __thiscall DestroyCharTemplate(FR6CharTemplate* charTemplate);

__declspec(naked) void __thiscall DestroyEightByteArrayStorageWithOwnGuard(FArray* array);

__declspec(naked) void __thiscall DestroyEmbeddedEightByteArrayPair(FArray* array);

__declspec(naked) void __thiscall DestroyRecordArrayAt14(void* record);

void __thiscall DestroySixteenByteArrayStorage(FArray* array);

void __thiscall DestroyTenStrings(void* strings);

void __thiscall DestroyWordArrayStorage(FArray* array);

uint __thiscall FR6CharTemplate_GetData(
    FR6CharTemplate* charTemplate, const ushort* baseName, int fileKind);

UClass* __thiscall FR6CharTemplate_GetPawnClass(FR6CharTemplate* charTemplate);

void* __thiscall FTextFile_Construct(
    void* textFile, const ushort* baseName, const ushort* directory, const ushort* extension);

int __thiscall FTextFile_CreateFileReader(void* textFile);

void __thiscall FTextFile_Destroy(void* textFile);

void __thiscall FTextFile_Init(
    void* textFile, const ushort* baseName, const ushort* directory, const ushort* extension);

int __thiscall FTextFile_ReadInt(void* textFile, const ushort* key);

int __thiscall FTextFile_ReadLine(void* textFile, ushort* lineBuffer, int maxCharacters);

FString* __thiscall FTextFile_ReadString(void* textFile, FString* result, const ushort* key);

__declspec(naked) void __thiscall ForwardEightByteArrayDestruction(FArray* array);

__declspec(naked) void __thiscall ForwardSixteenByteArrayDestruction(FArray* array);

__declspec(naked) void __thiscall ForwardTwelveByteArrayDestruction(FArray* array);

__declspec(naked) void __thiscall ForwardWordArrayDestruction(FArray* array);

void __cdecl FreeThroughGlobalAllocator(void* memory);

// Shared class-facing export bodies retain explicit ECX receivers.
void __thiscall DispatchSetCrouchBlend(UObject* object, float fCrouchBlend);

void __thiscall SharedNoOp(void* object);

FR6CharTemplate* __thiscall InitializeCharTemplate(FR6CharTemplate* charTemplate);

__declspec(naked) void __cdecl MatSubActionBaseCleanupExceptionHandler(void);

__declspec(naked) void __cdecl NavigationBaseOnlyDestructionExceptionHandler(void);

__declspec(naked) void __cdecl ObjectBaseConstructionExceptionHandler(void);

__declspec(naked) void __stdcall _eh_vector_constructor_iterator_(void* elementCursor, uint elementSize,
    int elementCount, void (__thiscall* constructElement)(void*), void (__thiscall* destroyElement)(void*));

__declspec(naked) void __stdcall _eh_vector_copy_constructor_iterator_(void* destinationCursor, void* sourceCursor,
    uint elementSize, int elementCount, void (__thiscall* copyConstructElement)(void*, void*),
    void (__thiscall* destroyElement)(void*));
