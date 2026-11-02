#pragma once

// PE32 collision-result storage used by the marker traces; address fields are native four-byte words.
// Plain coordinate storage preserves the inlined initialization without constructing additional FVector objects.
struct NativeCheckResult32
{
    struct VectorStorage { float X, Y, Z; };
    uint nextAddress; // +0
    uint actorAddress; // +4
    VectorStorage Location; // +8
    VectorStorage Normal; // +20
    uint primitiveAddress; // +32
    float Time; // +36
    int Item; // +40
    uint materialAddress; // +44; total native size 48 bytes
};
