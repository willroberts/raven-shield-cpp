#include "native_shared_entries.hpp"
#include "native_exception_data.hpp"
#include "native_runtime_entries.hpp"
#include "native_exception_records.hpp"
#include "native_import_slots.hpp"

// Descriptive text names identify existing native strings, not recovered original variable names.
// R6Engine.dll data @ 10054340 : nativePathFTextFileH
extern const char nativePathFTextFileH[24];

// R6Engine.dll data @ 100542d8 : nativeTextFTextFileClose
extern const ushort nativeTextFTextFileClose[17];

// R6Engine.dll data @ 100542fc : nativeTextFTextFileCreateFileReader
extern const ushort nativeTextFTextFileCreateFileReader[28];

// R6Engine.dll data @ 100545d4 : nativeTextFTextFileDestructorFTextFile
extern const ushort nativeTextFTextFileDestructorFTextFile[22];

// R6Engine.dll data @ 100545a8 : nativeTextFTextFileFTextFile
extern const ushort nativeTextFTextFileFTextFile[21];

// R6Engine.dll data @ 100542b8 : nativeTextFTextFileInit
extern const ushort nativeTextFTextFileInit[16];

// R6Engine.dll data @ 10054394 : nativeTextFTextFileReadInt
extern const ushort nativeTextFTextFileReadInt[19];

// R6Engine.dll data @ 10054358 : nativeTextFTextFileReadLine
extern const ushort nativeTextFTextFileReadLine[20];

// R6Engine.dll data @ 100543bc : nativeTextFTextFileReadString
extern const ushort nativeTextFTextFileReadString[22];

// R6Engine.dll data @ 10054334 : nativeTextMBOpenFTextFileStorage1
extern const char nativeTextMBOpenFTextFileStorage1[9];

// R6Engine.dll data @ 10054380 : nativeTextMBOpenFTextFileStorage2
extern const char nativeTextMBOpenFTextFileStorage2[8];

// R6Engine.dll data @ 10054388 : nativeTextMBWrite
extern const char nativeTextMBWrite[10];

// Native helper declarations match the canonical definitions below.
int __thiscall FTextFile_Close(void* textFile);
__declspec(naked) __declspec(noreturn) void __cdecl TextFileCloseCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl TextFileCloseCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl TextFileConstructorCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl TextFileConstructorCatchPointer(void);
__declspec(naked) void __cdecl TextFileConstructorState0Cleanup(void);
__declspec(naked) void __cdecl TextFileConstructorState1Cleanup(void);
__declspec(naked) void __cdecl TextFileConstructorState2Cleanup(void);
__declspec(naked) void __cdecl TextFileConstructorState3Cleanup(void);
__declspec(naked) __declspec(noreturn) void __cdecl TextFileCreateReaderCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl TextFileCreateReaderCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl TextFileDestructorCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl TextFileDestructorCatchPointer(void);
__declspec(naked) void __cdecl TextFileDestructorState0Cleanup(void);
__declspec(naked) void __cdecl TextFileDestructorState1Cleanup(void);
__declspec(naked) void __cdecl TextFileDestructorState2Cleanup(void);
__declspec(naked) void __cdecl TextFileDestructorState3Cleanup(void);
__declspec(naked) __declspec(noreturn) void __cdecl TextFileInitCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl TextFileInitCatchPointer(void);
__declspec(naked) void __cdecl TextFileInitState1Cleanup(void);
__declspec(naked) void __cdecl TextFileInitState2Cleanup(void);
__declspec(naked) __declspec(noreturn) void __cdecl TextFileReadIntCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl TextFileReadIntCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl TextFileReadLineCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl TextFileReadLineCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl TextFileReadStringCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl TextFileReadStringCatchPointer(void);
__declspec(naked) void __cdecl TextFileReadStringState0Cleanup(void);
__declspec(naked) void __cdecl TextFileReadStringState2Cleanup(void);

// R6Engine.dll data @ 1005df4c : textFileReadLineUnwindMap
// Retains prior-state/cleanup pairs, including the native empty transitions.
const NativeUnwindEntry textFileReadLineUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005df5c : textFileReadLineCatchMap
// Retains exact four-word pointer/catch-all records and the signed caught-pointer frame displacement.
const NativeCatchEntry textFileReadLineCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&TextFileReadLineCatchPointer) },
    { 0, 0, 0, ((uint)&TextFileReadLineCatchContext) }
};

// R6Engine.dll data @ 1005df7c : textFileReadLineTryMap
// Bounds the guarded states and their two private handlers.
const NativeTryBlock textFileReadLineTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&textFileReadLineCatchMap) }
};

// R6Engine.dll data @ 1005df90 : textFileReadLineFuncInfo
// Binds ReadLine to its exact selected MSVC state and handler maps.
const NativeFunctionInfoPrefix textFileReadLineFuncInfo = { 0x19930520, 0x2, ((uint)&textFileReadLineUnwindMap), 0x1,
    ((uint)&textFileReadLineTryMap), 0 };

// R6Engine.dll data @ 1005dfac : textFileReadIntUnwindMap
// Retains prior-state/cleanup pairs, including the native empty transitions.
const NativeUnwindEntry textFileReadIntUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005dfbc : textFileReadIntCatchMap
// Retains exact four-word pointer/catch-all records and the signed caught-pointer frame displacement.
const NativeCatchEntry textFileReadIntCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&TextFileReadIntCatchPointer) },
    { 0, 0, 0, ((uint)&TextFileReadIntCatchContext) }
};

// R6Engine.dll data @ 1005dfdc : textFileReadIntTryMap
// Bounds the guarded states and their two private handlers.
const NativeTryBlock textFileReadIntTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&textFileReadIntCatchMap) }
};

// R6Engine.dll data @ 1005dff0 : textFileReadIntFuncInfo
// Binds ReadInt to its exact selected MSVC state and handler maps.
const NativeFunctionInfoPrefix textFileReadIntFuncInfo = { 0x19930520, 0x2, ((uint)&textFileReadIntUnwindMap), 0x1,
    ((uint)&textFileReadIntTryMap), 0 };

// R6Engine.dll data @ 1005e00c : textFileReadStringUnwindMap
// Retains prior-state/cleanup pairs, including the native empty transitions.
const NativeUnwindEntry textFileReadStringUnwindMap[4] = {
    { -1, ((uint)&TextFileReadStringState0Cleanup) },
    { 0, 0 },
    { 0x1, ((uint)&TextFileReadStringState2Cleanup) },
    { 0, 0 }
};

// R6Engine.dll data @ 1005e02c : textFileReadStringCatchMap
// Retains exact four-word pointer/catch-all records and the signed caught-pointer frame displacement.
const NativeCatchEntry textFileReadStringCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -40, ((uint)&TextFileReadStringCatchPointer) },
    { 0, 0, 0, ((uint)&TextFileReadStringCatchContext) }
};

// R6Engine.dll data @ 1005e04c : textFileReadStringTryMap
// Bounds the guarded states and their two private handlers.
const NativeTryBlock textFileReadStringTryMap[1] = {
    { 0x1, 0x2, 0x3, 0x2, ((uint)&textFileReadStringCatchMap) }
};

// R6Engine.dll data @ 1005e060 : textFileReadStringFuncInfo
// Binds ReadString to its exact selected MSVC state and handler maps.
const NativeFunctionInfoPrefix textFileReadStringFuncInfo = { 0x19930520, 0x4, ((uint)&textFileReadStringUnwindMap),
    0x1, ((uint)&textFileReadStringTryMap), 0 };

// Routes ReadLine through its selected C++ exception metadata.
__declspec(naked) void __cdecl TextFileReadLineExceptionHandler(void);
// Routes ReadInt through its selected C++ exception metadata.
__declspec(naked) void __cdecl TextFileReadIntExceptionHandler(void);
// Routes ReadString through its selected C++ exception metadata.
__declspec(naked) void __cdecl TextFileReadStringExceptionHandler(void);

// R6Engine.dll data @ 1005de1c : textFileInitUnwindMap
// Retains prior-state/cleanup pairs, including the native empty transitions.
const NativeUnwindEntry textFileInitUnwindMap[4] = {
    { -1, 0 },
    { 0, ((uint)&TextFileInitState1Cleanup) },
    { 0x1, ((uint)&TextFileInitState2Cleanup) },
    { -1, 0 }
};

// R6Engine.dll data @ 1005de3c : textFileInitCatchMap
// Retains four-word pointer and catch-all records; the pointer arrives at inherited EBP-0x18.
const NativeCatchEntry textFileInitCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&TextFileInitCatchPointer) },
    { 0, 0, 0, ((uint)&TextFileInitCatchContext) }
};

// R6Engine.dll data @ 1005de5c : textFileInitTryMap
// Bounds the guarded states and their two private handlers.
const NativeTryBlock textFileInitTryMap[1] = {
    { 0, 0x2, 0x3, 0x2, ((uint)&textFileInitCatchMap) }
};

// R6Engine.dll data @ 1005de70 : textFileInitFuncInfo
// Binds Init to its exact selected MSVC state and handler maps.
const NativeFunctionInfoPrefix textFileInitFuncInfo = { 0x19930520, 0x4, ((uint)&textFileInitUnwindMap), 0x1,
    ((uint)&textFileInitTryMap), 0 };

// R6Engine.dll data @ 1005de8c : textFileCloseUnwindMap
// Retains prior-state/cleanup pairs, including the native empty transitions.
const NativeUnwindEntry textFileCloseUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005de9c : textFileCloseCatchMap
// Retains four-word pointer and catch-all records; the pointer arrives at inherited EBP-0x18.
const NativeCatchEntry textFileCloseCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&TextFileCloseCatchPointer) },
    { 0, 0, 0, ((uint)&TextFileCloseCatchContext) }
};

// R6Engine.dll data @ 1005debc : textFileCloseTryMap
// Bounds the guarded states and their two private handlers.
const NativeTryBlock textFileCloseTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&textFileCloseCatchMap) }
};

// R6Engine.dll data @ 1005ded0 : textFileCloseFuncInfo
// Binds Close to its exact selected MSVC state and handler maps.
const NativeFunctionInfoPrefix textFileCloseFuncInfo = { 0x19930520, 0x2, ((uint)&textFileCloseUnwindMap), 0x1,
    ((uint)&textFileCloseTryMap), 0 };

// R6Engine.dll data @ 1005deec : textFileCreateReaderUnwindMap
// Retains prior-state/cleanup pairs, including the native empty transitions.
const NativeUnwindEntry textFileCreateReaderUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005defc : textFileCreateReaderCatchMap
// Retains four-word pointer and catch-all records; the pointer arrives at inherited EBP-0x18.
const NativeCatchEntry textFileCreateReaderCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&TextFileCreateReaderCatchPointer) },
    { 0, 0, 0, ((uint)&TextFileCreateReaderCatchContext) }
};

// R6Engine.dll data @ 1005df1c : textFileCreateReaderTryMap
// Bounds the guarded states and their two private handlers.
const NativeTryBlock textFileCreateReaderTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&textFileCreateReaderCatchMap) }
};

// R6Engine.dll data @ 1005df30 : textFileCreateReaderFuncInfo
// Binds CreateFileReader to its exact selected MSVC state and handler maps.
const NativeFunctionInfoPrefix textFileCreateReaderFuncInfo = { 0x19930520, 0x2, ((uint)&textFileCreateReaderUnwindMap),
    0x1, ((uint)&textFileCreateReaderTryMap), 0 };

// Routes Init through its selected C++ exception metadata.
__declspec(naked) void __cdecl TextFileInitExceptionHandler(void);
// Routes Close through its selected C++ exception metadata.
__declspec(naked) void __cdecl TextFileCloseExceptionHandler(void);
// Routes CreateFileReader through its selected C++ exception metadata.
__declspec(naked) void __cdecl TextFileCreateFileReaderExceptionHandler(void);

// R6Engine.dll data @ 1005e28c : textFileConstructorUnwindMap
// Releases constructed strings in reverse order; guarded Init and catch states return to the four-member state.
const NativeUnwindEntry textFileConstructorUnwindMap[6] = {
    { -1, ((uint)&TextFileConstructorState0Cleanup) },
    { 0, ((uint)&TextFileConstructorState1Cleanup) },
    { 0x1, ((uint)&TextFileConstructorState2Cleanup) },
    { 0x2, ((uint)&TextFileConstructorState3Cleanup) },
    { 0x3, 0 },
    { 0x3, 0 }
};

// R6Engine.dll data @ 1005e2bc : textFileConstructorCatchMap
// Retains the unsigned-short-pointer and catch-all four-word handler records at inherited EBP-0x1c.
const NativeCatchEntry textFileConstructorCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&TextFileConstructorCatchPointer) },
    { 0, 0, 0, ((uint)&TextFileConstructorCatchContext) }
};

// R6Engine.dll data @ 1005e2dc : textFileConstructorTryMap
// Guards state4 (Init) only, after all four member strings have been constructed.
const NativeTryBlock textFileConstructorTryMap[1] = {
    { 0x4, 0x4, 0x5, 0x2, ((uint)&textFileConstructorCatchMap) }
};

// R6Engine.dll data @ 1005e2f0 : textFileConstructorFuncInfo
// Binds the six-state constructor frame to its cleanup map and two catch handlers.
const NativeFunctionInfoPrefix textFileConstructorFuncInfo = { 0x19930520, 0x6, ((uint)&textFileConstructorUnwindMap),
    0x1, ((uint)&textFileConstructorTryMap), 0 };

// Routes text-file construction through its selected C++ exception metadata.
__declspec(naked) void __cdecl TextFileConstructorExceptionHandler(void);

// R6Engine.dll data @ 1005e30c : textFileDestructorUnwindMap
// Maps private states to prior states and cleanup entries; zero actions retain native empty transitions.
const NativeUnwindEntry textFileDestructorUnwindMap[6] = {
    { -1, ((uint)&TextFileDestructorState0Cleanup) },
    { 0, ((uint)&TextFileDestructorState1Cleanup) },
    { 0x1, ((uint)&TextFileDestructorState2Cleanup) },
    { 0x2, ((uint)&TextFileDestructorState3Cleanup) },
    { 0x3, 0 },
    { 0x3, 0 }
};

// R6Engine.dll data @ 1005e33c : textFileDestructorCatchMap
// Retains four-word unsigned-short-pointer and catch-all handler records with signed frame displacements.
const NativeCatchEntry textFileDestructorCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&TextFileDestructorCatchPointer) },
    { 0, 0, 0, ((uint)&TextFileDestructorCatchContext) }
};

// R6Engine.dll data @ 1005e35c : textFileDestructorTryMap
// Bounds the guarded private states and their two catch handlers.
const NativeTryBlock textFileDestructorTryMap[1] = {
    { 0x4, 0x4, 0x5, 0x2, ((uint)&textFileDestructorCatchMap) }
};

// R6Engine.dll data @ 1005e370 : textFileDestructorFuncInfo
// Binds the selected MSVC exception dispatcher to its exact state, try and catch maps.
const NativeFunctionInfoPrefix textFileDestructorFuncInfo = { 0x19930520, 0x6, ((uint)&textFileDestructorUnwindMap),
    0x1, ((uint)&textFileDestructorTryMap), 0 };

// Routes text-file destruction through its selected C++ exception metadata.
__declspec(naked) void __cdecl TextFileDestructorExceptionHandler(void);

// R6Engine.dll @ 1003e470 : FTextFile::Init
// Builds directory + base name + extension, releases both temporaries and clears write/open DWORDs in that order.
void __thiscall FTextFile_Init(
    void* textFile, const ushort* baseName, const ushort* directory, const ushort* extension)
{
    struct NativeFrameView { // Explicit native slots; saved registers and inherited-frame handlers remain separate.
        uint savedEdi, savedEsi, savedEbx;
        byte locals[0x24];
        void* previousExceptionList;
        void* handler;
        int state;
    } frame;
    frame.state = -1;
    frame.handler = (void*)&TextFileInitExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    byte* nativeFrame = reinterpret_cast<byte*>(&frame.state) + 4;
    *reinterpret_cast<void**>(nativeFrame - 0x10) = &frame.savedEdi;
    byte* file = reinterpret_cast<byte*>(textFile);
    const ushort* directoryInput = directory;
    frame.state = 0;
    if (directoryInput) *reinterpret_cast<FString*>(file + 0x24) = directoryInput;
    const ushort* extensionInput = extension;
    if (extensionInput) *reinterpret_cast<FString*>(file + 0x30) = extensionInput;
    FString* directoryAndName = reinterpret_cast<FString*>(nativeFrame - 0x30);
    FString* completeName = reinterpret_cast<FString*>(nativeFrame - 0x24);
    using AddText = FString* (__thiscall*)(FString*, FString*, const ushort*);
    FString* first = reinterpret_cast<AddText&>(FStringAddTextImport)(
        reinterpret_cast<FString*>(file + 0x24), directoryAndName, baseName);
    FString* suffix = reinterpret_cast<FString*>(file + 0x30);
    *(byte*)&frame.state = 1;
    using AddString = FString* (__thiscall*)(FString*, FString*, const FString*);
    FString* second = reinterpret_cast<AddString&>(FStringAddStringImport)(first, completeName, suffix);
    *(byte*)&frame.state = 2;
    *reinterpret_cast<FString*>(file + 0x18) = *second;
    *(byte*)&frame.state = 1;
    FString::~FString(completeName);
    *(byte*)&frame.state = 0;
    FString::~FString(directoryAndName);
    *reinterpret_cast<uint*>(file + 0x10) = 0;
    *reinterpret_cast<uint*>(file + 0xc) = 0; // Cursor is not reset.
    ExceptionList = frame.previousExceptionList;
}

// R6Engine.dll @ 1003e520 : TextFileInitCatchPointer
// Throws the unsigned-short pointer from inherited EBP-0x18 by value through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl TextFileInitCatchPointer(void)
{
    __asm {
        mov edx,dword ptr [ebp-0x18]
        push offset unsignedShortPointerThrowInfo
        lea eax,[ebp-0x14]
        push eax
        mov dword ptr [ebp-0x14],edx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1003e560 : FTextFile::Close
// Saves the leading text string when write is nonzero, returns the full save result and clears only open.
int __thiscall FTextFile_Close(void* textFile)
{
    struct NativeFrameView { // Explicit native slots; saved registers and inherited-frame handlers remain separate.
        uint savedEdi, savedEsi, savedEbx;
        byte locals[0xc];
        void* previousExceptionList;
        void* handler;
        int state;
    } frame;
    frame.state = -1;
    frame.handler = (void*)&TextFileCloseExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    byte* nativeFrame = reinterpret_cast<byte*>(&frame.state) + 4;
    *reinterpret_cast<void**>(nativeFrame - 0x10) = &frame.savedEdi;
    byte* file = reinterpret_cast<byte*>(textFile);
    const uint write = *reinterpret_cast<uint*>(file + 0x10);
    frame.state = 0;
    int saved = 1;
    if (write) {
        const ushort* filename = **reinterpret_cast<FString*>(file + 0x18);
        FFileManager** managerSlot = *reinterpret_cast<FFileManager***>(&CoreGFileManagerImport);
        FFileManager* manager = *managerSlot;
        using Save = int (__cdecl*)(FString*, const ushort*, FFileManager*);
        saved = reinterpret_cast<Save&>(CoreAppSaveStringToFileImport)(reinterpret_cast<FString*>(file), filename, manager);
    }
    *reinterpret_cast<uint*>(file + 0xc) = 0;
    ExceptionList = frame.previousExceptionList;
    return saved;
}

// R6Engine.dll @ 1003e5cb : TextFileCloseCatchPointer
// Throws the unsigned-short pointer from inherited EBP-0x18 by value through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl TextFileCloseCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x18]
        push offset unsignedShortPointerThrowInfo
        lea ecx,[ebp-0x14]
        push ecx
        mov dword ptr [ebp-0x14],eax
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1003e600 : FTextFile::CreateFileReader
// Loads the filename into the leading text string; success sets open before acquiring its reader cursor.
int __thiscall FTextFile_CreateFileReader(void* textFile)
{
    struct NativeFrameView { // Explicit native slots; saved registers and inherited-frame handlers remain separate.
        uint savedEdi, savedEsi, savedEbx;
        byte locals[0xc];
        void* previousExceptionList;
        void* handler;
        int state;
    } frame;
    frame.state = -1;
    frame.handler = (void*)&TextFileCreateFileReaderExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    byte* nativeFrame = reinterpret_cast<byte*>(&frame.state) + 4;
    *reinterpret_cast<void**>(nativeFrame - 0x10) = &frame.savedEdi;
    byte* file = reinterpret_cast<byte*>(textFile);
    const uint wasOpen = *reinterpret_cast<uint*>(file + 0xc);
    frame.state = 0;
    if (wasOpen) appFailAssert(nativeTextMBOpenFTextFileStorage1, nativePathFTextFileH, 0x66);
    const ushort* filename = **reinterpret_cast<FString*>(file + 0x18);
    FFileManager** managerSlot = *reinterpret_cast<FFileManager***>(&CoreGFileManagerImport);
    FFileManager* manager = *managerSlot;
    using Load = int (__cdecl*)(FString*, const ushort*, FFileManager*);
    int loaded = reinterpret_cast<Load&>(CoreAppLoadFileToStringImport)(reinterpret_cast<FString*>(file), filename, manager);
    int success = 0;
    if (loaded) {
        *reinterpret_cast<uint*>(file + 0xc) = 1;
        const ushort* cursor = **reinterpret_cast<FString*>(file);
        *reinterpret_cast<const ushort**>(file + 0x14) = cursor;
        success = 1;
    }
    ExceptionList = frame.previousExceptionList;
    return success;
}

// R6Engine.dll @ 1003e6a2 : TextFileCreateReaderCatchPointer
// Throws the unsigned-short pointer from inherited EBP-0x18 by value through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl TextFileCreateReaderCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x18]
        push offset unsignedShortPointerThrowInfo
        lea ecx,[ebp-0x14]
        push ecx
        mov dword ptr [ebp-0x14],eax
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1003e6e0 : FTextFile::ReadLine
// Advances the live cursor through ParseLine and returns one whenever the initial cursor character was nonzero.
int __thiscall FTextFile_ReadLine(void* textFile, ushort* lineBuffer, int maxCharacters)
{
    struct NativeFrameView { // Explicit native slots; saved registers and inherited-frame handlers remain separate.
        uint savedEdi, savedEsi, savedEbx;
        byte locals[0xc];
        void* previousExceptionList;
        void* handler;
        int state;
    } frame;
    frame.state = -1;
    frame.handler = (void*)&TextFileReadLineExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    byte* nativeFrame = reinterpret_cast<byte*>(&frame.state) + 4;
    *reinterpret_cast<void**>(nativeFrame - 0x10) = &frame.savedEdi;
    byte* file = reinterpret_cast<byte*>(textFile);
    const uint write = *reinterpret_cast<uint*>(file + 0x10);
    frame.state = 0;
    if (write) appFailAssert(nativeTextMBWrite, nativePathFTextFileH, 0x86);
    if (!*reinterpret_cast<uint*>(file + 0xc))
        appFailAssert(nativeTextMBOpenFTextFileStorage2, nativePathFTextFileH, 0x87);
    const ushort* cursor = *reinterpret_cast<const ushort**>(file + 0x14);
    const bool nonempty = *cursor != 0; // No null-cursor or length guard exists.
    if (nonempty) {
        using ParseLine = int (__cdecl*)(const ushort**, ushort*, int, int);
        const int limit = maxCharacters;
        ushort* output = lineBuffer;
        reinterpret_cast<ParseLine&>(CoreParseLineImport)(
            reinterpret_cast<const ushort**>(file + 0x14), output, limit, 0);
    }
    ExceptionList = frame.previousExceptionList;
    return nonempty ? 1 : 0; // Parser status is ignored.
}

// R6Engine.dll @ 1003e780 : TextFileReadLineCatchPointer
// Throws the unsigned-short pointer from inherited EBP-0x18 by value through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl TextFileReadLineCatchPointer(void)
{
    __asm {
        mov edx,dword ptr [ebp-0x18]
        push offset unsignedShortPointerThrowInfo
        lea eax,[ebp-0x14]
        push eax
        mov dword ptr [ebp-0x14],edx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1003e7d0 : FTextFile::ReadInt
// Scans up to EOF or a nonzero integer-parser result and returns the retained parsed slot, initially zero.
int __thiscall FTextFile_ReadInt(void* textFile, const ushort* key)
{
    struct NativeFrameView { // Explicit native slots; saved registers and inherited-frame handlers remain separate.
        uint savedEdi, savedEsi, savedEbx;
        byte locals[0x810];
        void* previousExceptionList;
        void* handler;
        int state;
    } frame;
    frame.state = -1;
    frame.handler = (void*)&TextFileReadIntExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    byte* nativeFrame = reinterpret_cast<byte*>(&frame.state) + 4;
    *reinterpret_cast<void**>(nativeFrame - 0x10) = &frame.savedEdi;
    byte* file = reinterpret_cast<byte*>(textFile);
    const uint open = *reinterpret_cast<uint*>(file + 0xc);
    frame.state = 0;
    if (!open) appFailAssert(nativeTextMBOpenFTextFileStorage2, nativePathFTextFileH, 0x97);
    if (*reinterpret_cast<uint*>(file + 0x10)) appFailAssert(nativeTextMBWrite, nativePathFTextFileH, 0x98);
    using ParseInteger = int (__cdecl*)(const ushort*, const ushort*, int*);
    ParseInteger parse = reinterpret_cast<ParseInteger&>(CoreParseIntegerImport);
    int& value = *reinterpret_cast<int*>(nativeFrame - 0x14);
    value = 0;
    const ushort* savedKey = key;
    ushort* line = reinterpret_cast<ushort*>(nativeFrame - 0x81c);
    int matched = 0;
    while (!matched && FTextFile_ReadLine(textFile, line, 0x400)) matched = parse(line, savedKey, &value);
    int returned = value; // Retains parser writes from failed matches and from the final line at EOF.
    ExceptionList = frame.previousExceptionList;
    return returned;
}

// R6Engine.dll @ 1003e873 : TextFileReadIntCatchPointer
// Throws the unsigned-short pointer from inherited EBP-0x1c by value through EBP-0x18.
__declspec(naked) __declspec(noreturn) void __cdecl TextFileReadIntCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x1c]
        push offset unsignedShortPointerThrowInfo
        lea ecx,[ebp-0x18]
        push ecx
        mov dword ptr [ebp-0x18],eax
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1003e8c0 : FTextFile::ReadString
// Scans into a temporary string, copy-constructs the hidden result and protects its completed lifetime on unwind.
FString* __thiscall FTextFile_ReadString(void* textFile, FString* result, const ushort* key)
{
    struct NativeFrameView { // Explicit native slots; saved registers and inherited-frame handlers remain separate.
        uint savedEdi, savedEsi, savedEbx;
        byte locals[0x81c];
        void* previousExceptionList;
        void* handler;
        int state;
    } frame;
    frame.state = -1;
    frame.handler = (void*)&TextFileReadStringExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    byte* nativeFrame = reinterpret_cast<byte*>(&frame.state) + 4;
    *reinterpret_cast<void**>(nativeFrame - 0x10) = &frame.savedEdi;
    byte* file = reinterpret_cast<byte*>(textFile);
    uint& outputLifetime = *reinterpret_cast<uint*>(nativeFrame - 0x14);
    outputLifetime = 0;
    const uint open = *reinterpret_cast<uint*>(file + 0xc);
    frame.state = 1;
    if (!open) appFailAssert(nativeTextMBOpenFTextFileStorage2, nativePathFTextFileH, 0xa8);
    if (*reinterpret_cast<uint*>(file + 0x10)) appFailAssert(nativeTextMBWrite, nativePathFTextFileH, 0xa9);
    FString* parsed = reinterpret_cast<FString*>(nativeFrame - 0x24);
    FString::FString(parsed);
    const ushort* savedKey = key;
    using ParseString = int (__cdecl*)(const ushort*, const ushort*, FString*);
    ParseString parse = reinterpret_cast<ParseString&>(CoreParseStringImport);
    *(byte*)&frame.state = 2;
    ushort* line = reinterpret_cast<ushort*>(nativeFrame - 0x828);
    int matched = 0;
    while (!matched && FTextFile_ReadLine(textFile, line, 0x400)) matched = parse(line, savedKey, parsed);
    FString* output = result;
    FString::FString(output, parsed);
    outputLifetime |= 1;
    *(byte*)&frame.state = 1;
    FString::~FString(parsed); // A throw still destroys the completed hidden output through the existing flag funclet.
    ExceptionList = frame.previousExceptionList;
    return output;
}

// R6Engine.dll @ 1003e9b8 : TextFileReadStringCatchPointer
// Throws the unsigned-short pointer from inherited EBP-0x28 by value through EBP-0x18.
__declspec(naked) __declspec(noreturn) void __cdecl TextFileReadStringCatchPointer(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x28]
        push offset unsignedShortPointerThrowInfo
        lea edx,[ebp-0x18]
        push edx
        mov dword ptr [ebp-0x18],ecx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1003ee60 : FTextFile::FTextFile
// Constructs four strings, guards Init after all four exist and returns this while removing twelve argument bytes.
void* __thiscall FTextFile_Construct(
    void* textFile, const ushort* baseName, const ushort* directory, const ushort* extension)
{
    struct NativeFrameView { // Explicit native slots; saved registers and inherited-frame handlers remain separate.
        uint savedEdi, savedEsi, savedEbx;
        byte locals[0x10];
        void* previousExceptionList;
        void* handler;
        int state;
    } frame;
    frame.state = -1;
    frame.handler = (void*)&TextFileConstructorExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    byte* nativeFrame = reinterpret_cast<byte*>(&frame.state) + 4;
    *reinterpret_cast<void**>(nativeFrame - 0x10) = &frame.savedEdi;
    byte* file = reinterpret_cast<byte*>(textFile);
    *reinterpret_cast<void**>(nativeFrame - 0x18) = textFile;
    FString::FString(reinterpret_cast<FString*>(file));
    frame.state = 0;
    FString::FString(reinterpret_cast<FString*>(file + 0x18));
    *(byte*)&frame.state = 1;
    FString::FString(reinterpret_cast<FString*>(file + 0x24));
    *(byte*)&frame.state = 2;
    FString::FString(reinterpret_cast<FString*>(file + 0x30));
    const ushort* savedExtension = extension;
    const ushort* savedDirectory = directory;
    const ushort* savedBase = baseName;
    *(byte*)&frame.state = 4;
    FTextFile_Init(textFile, savedBase, savedDirectory, savedExtension);
    ExceptionList = frame.previousExceptionList;
    return textFile;
}

// R6Engine.dll @ 1003eee2 : TextFileConstructorCatchPointer
// Throws the caught unsigned-short pointer by value through the inherited constructor frame.
__declspec(naked) __declspec(noreturn) void __cdecl TextFileConstructorCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x1c]
        push offset unsignedShortPointerThrowInfo
        lea ecx,[ebp-0x14]
        push ecx
        mov dword ptr [ebp-0x14],eax
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1003ef20 : FTextFile::~FTextFile
// Closes a nonzero open flag, then destroys strings at +0x30, +0x24, +0x18 and +0 with exact private EH states.
void __thiscall FTextFile_Destroy(void* textFile)
{
    struct NativeFrameView { // Explicit native slots; saved registers and inherited-frame handlers remain separate.
        uint savedEdi, savedEsi, savedEbx;
        byte locals[0x10];
        void* previousExceptionList;
        void* handler;
        int state;
    } frame;
    frame.state = -1;
    frame.handler = (void*)&TextFileDestructorExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    byte* nativeFrame = reinterpret_cast<byte*>(&frame.state) + 4;
    *reinterpret_cast<void**>(nativeFrame - 0x10) = &frame.savedEdi;
    byte* file = reinterpret_cast<byte*>(textFile);
    *reinterpret_cast<void**>(nativeFrame - 0x18) = textFile;
    frame.state = 0;
    const uint open = *reinterpret_cast<uint*>(file + 0xc);
    *(byte*)&frame.state = 4;
    if (open) FTextFile_Close(textFile);
    frame.state = 2;
    FString::~FString(reinterpret_cast<FString*>(file + 0x30));
    *(byte*)&frame.state = 1;
    FString::~FString(reinterpret_cast<FString*>(file + 0x24));
    *(byte*)&frame.state = 0;
    FString::~FString(reinterpret_cast<FString*>(file + 0x18));
    frame.state = -1;
    FString::~FString(reinterpret_cast<FString*>(file));
    ExceptionList = frame.previousExceptionList;
}

// R6Engine.dll @ 1003efa7 : TextFileDestructorCatchPointer
// Throws the caught unsigned-short pointer by value through the inherited text-file destructor frame.
__declspec(naked) __declspec(noreturn) void __cdecl TextFileDestructorCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x1c]
        push offset unsignedShortPointerThrowInfo
        lea ecx,[ebp-0x14]
        push ecx
        mov dword ptr [ebp-0x14],eax
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100451f0 : TextFileInitState1Cleanup
// Destroys Init's directory/base-name temporary at inherited EBP-0x30.
__declspec(naked) void __cdecl TextFileInitState1Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x30]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 100451f9 : TextFileInitState2Cleanup
// Destroys Init's final-filename temporary at inherited EBP-0x24.
__declspec(naked) void __cdecl TextFileInitState2Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x24]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10045250 : TextFileReadStringState2Cleanup
// Destroys ReadString's parsed temporary at inherited EBP-0x24.
__declspec(naked) void __cdecl TextFileReadStringState2Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x24]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10045259 : TextFileReadStringState0Cleanup
// Clears output lifetime bit0 before destroying the completed hidden result, or returns when it is clear.
__declspec(naked) void __cdecl TextFileReadStringState0Cleanup(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x14]
        // Only bit0 tracks this output lifetime; preserve every other flag bit.
        and eax,0x1
        je TextFileReadStringState0CleanupBranch0
        // Clear the lifetime bit before calling the output destructor.
        and dword ptr [ebp-0x14],0xfffffffe
        mov ecx,dword ptr [ebp+0x8]
        jmp dword ptr [FStringDestructorImport]
    TextFileReadStringState0CleanupBranch0:
        ret
    }
}

// R6Engine.dll @ 10045330 : TextFileConstructorState0Cleanup
// Destroys the constructed leading string through saved this at parent EBP-0x18.
__declspec(naked) void __cdecl TextFileConstructorState0Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x18]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10045339 : TextFileConstructorState1Cleanup
// Destroys the constructed string at +0x18 through saved this at parent EBP-0x18.
__declspec(naked) void __cdecl TextFileConstructorState1Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x18]
        add ecx,0x18
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10045345 : TextFileConstructorState2Cleanup
// Destroys the constructed string at +0x24 through saved this at parent EBP-0x18.
__declspec(naked) void __cdecl TextFileConstructorState2Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x18]
        add ecx,0x24
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10045351 : TextFileConstructorState3Cleanup
// Destroys the constructed string at +0x30 through saved this at parent EBP-0x18.
__declspec(naked) void __cdecl TextFileConstructorState3Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x18]
        add ecx,0x30
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10045370 : TextFileDestructorState0Cleanup
// Destroys the leading string through the text-file pointer saved at parent EBP-0x18.
__declspec(naked) void __cdecl TextFileDestructorState0Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x18]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10045379 : TextFileDestructorState1Cleanup
// Destroys the string at +0x18 through the text-file pointer saved in the parent frame.
__declspec(naked) void __cdecl TextFileDestructorState1Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x18]
        add ecx,0x18
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10045385 : TextFileDestructorState2Cleanup
// Destroys the string at +0x24 through the text-file pointer saved in the parent frame.
__declspec(naked) void __cdecl TextFileDestructorState2Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x18]
        add ecx,0x24
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10045391 : TextFileDestructorState3Cleanup
// Destroys the string at +0x30 through the text-file pointer saved in the parent frame.
__declspec(naked) void __cdecl TextFileDestructorState3Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x18]
        add ecx,0x30
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 1003efbb : TextFileDestructorCatchContext
// Reports the FTextFile destructor context for its guarded close operation and rethrows.
__declspec(naked) __declspec(noreturn) void __cdecl TextFileDestructorCatchContext(void)
{
    __asm {
        push offset nativeTextFTextFileDestructorFTextFile
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1004539d : TextFileDestructorExceptionHandler
// Supplies the text-file destructor FuncInfo without changing its private dispatcher frame.
__declspec(naked) void __cdecl TextFileDestructorExceptionHandler(void)
{
    __asm {
        mov eax,offset textFileDestructorFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1003eef6 : TextFileConstructorCatchContext
// Reports the text-file construction context and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl TextFileConstructorCatchContext(void)
{
    __asm {
        push offset nativeTextFTextFileFTextFile
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1004535d : TextFileConstructorExceptionHandler
// Supplies the constructor FuncInfo while retaining the private exception-dispatch frame.
__declspec(naked) void __cdecl TextFileConstructorExceptionHandler(void)
{
    __asm {
        mov eax,offset textFileConstructorFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1003e534 : TextFileInitCatchContext
// Reports FTextFile::Init and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl TextFileInitCatchContext(void)
{
    __asm {
        push offset nativeTextFTextFileInit
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10045202 : TextFileInitExceptionHandler
// Supplies Init exception metadata without changing the inherited dispatcher frame.
__declspec(naked) void __cdecl TextFileInitExceptionHandler(void)
{
    __asm {
        mov eax,offset textFileInitFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1003e5df : TextFileCloseCatchContext
// Reports FTextFile::Close and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl TextFileCloseCatchContext(void)
{
    __asm {
        push offset nativeTextFTextFileClose
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10045210 : TextFileCloseExceptionHandler
// Supplies Close exception metadata without changing the inherited dispatcher frame.
__declspec(naked) void __cdecl TextFileCloseExceptionHandler(void)
{
    __asm {
        mov eax,offset textFileCloseFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1003e6b6 : TextFileCreateReaderCatchContext
// Reports FTextFile::CreateFileReader and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl TextFileCreateReaderCatchContext(void)
{
    __asm {
        push offset nativeTextFTextFileCreateFileReader
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10045220 : TextFileCreateFileReaderExceptionHandler
// Supplies CreateFileReader exception metadata without changing the inherited dispatcher frame.
__declspec(naked) void __cdecl TextFileCreateFileReaderExceptionHandler(void)
{
    __asm {
        mov eax,offset textFileCreateReaderFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1003e794 : TextFileReadLineCatchContext
// Reports FTextFile::ReadLine and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl TextFileReadLineCatchContext(void)
{
    __asm {
        push offset nativeTextFTextFileReadLine
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10045230 : TextFileReadLineExceptionHandler
// Supplies ReadLine exception metadata without changing the inherited dispatcher frame.
__declspec(naked) void __cdecl TextFileReadLineExceptionHandler(void)
{
    __asm {
        mov eax,offset textFileReadLineFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1003e887 : TextFileReadIntCatchContext
// Reports FTextFile::ReadInt and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl TextFileReadIntCatchContext(void)
{
    __asm {
        push offset nativeTextFTextFileReadInt
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10045240 : TextFileReadIntExceptionHandler
// Supplies ReadInt exception metadata without changing the inherited dispatcher frame.
__declspec(naked) void __cdecl TextFileReadIntExceptionHandler(void)
{
    __asm {
        mov eax,offset textFileReadIntFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1003e9cc : TextFileReadStringCatchContext
// Reports FTextFile::ReadString and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl TextFileReadStringCatchContext(void)
{
    __asm {
        push offset nativeTextFTextFileReadString
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10045273 : TextFileReadStringExceptionHandler
// Supplies ReadString exception metadata without changing the inherited dispatcher frame.
__declspec(naked) void __cdecl TextFileReadStringExceptionHandler(void)
{
    __asm {
        mov eax,offset textFileReadStringFuncInfo
        jmp __CxxFrameHandler
    }
}
