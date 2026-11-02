#pragma once

// Selected PE32 dynamic-array header view, corroborated by native reads/stores and FArray operations.
// Raw address storage avoids host pointer-size assumptions; element types and ownership remain unspecified.
struct NativeArrayHeader32
{
    uint dataAddress; // +0
    int count; // +4
    int capacity; // +8
};
