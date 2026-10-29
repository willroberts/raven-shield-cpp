#pragma once

// Native copy callbacks receive one float on the cdecl stack; callers ignore any returned value.
using FileCopyProgress = void(__cdecl *)(float);
