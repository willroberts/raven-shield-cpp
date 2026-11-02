#pragma once

// Descriptive names for the native typed-pointer guard metadata and shared diagnostic strings.
// The descriptor remains an opaque bounded view; no complete type_info or compiler layout is invented.
// R6Engine.dll data @ 1007432c : unsignedShortPointerTypeDescriptor
// Native decorated spelling .PAG identifies unsigned short*; the runtime may update descriptor state.
extern byte unsignedShortPointerTypeDescriptor[16];

// R6Engine.dll data @ 100567b8 : unsignedShortPointerThrowInfo
extern const ThrowInfo unsignedShortPointerThrowInfo;

// R6Engine.dll data @ 10049830 : unwindStringFormat
extern const ushort unwindStringFormat[3]; // Native UTF-16 "%s", including its terminator.

// R6Engine.dll data @ 10074534 : enginePackageName
extern ushort enginePackageName[9]; // Native UTF-16 "R6Engine", including its terminator.
