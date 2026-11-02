#pragma once

// Common first four native virtual slots, verified in the selected class tables.
// This is a partial address-word view, not a complete C++ vtable or a member-function pointer layout.
struct NativeObjectVtablePrefix
{
    uint queryInterfaceAddress; // +0
    uint addRefAddress; // +4
    uint releaseAddress; // +8
    uint deletingDestructorAddress; // +12
};

// ProcessEvent follows the four common object slots in the selected PE32 class tables.
// The current slot is read through this prefix; capturing the table does not snapshot its contents.
struct NativeEventVtablePrefix
{
    NativeObjectVtablePrefix object; // +0..+15
    uint processEventAddress; // +16
};

// Allocator dispatch retains the two preceding address words without naming unused operations.
// Free is the current code word at byte offset8; this prefix does not describe the complete FMalloc table.
struct NativeAllocatorVtablePrefix
{
    uint earlierAddresses[2]; // +0..+7
    uint freeAddress; // +8
};

// Partial PE32 actor control slots; gaps leave unrelated virtual methods unmodeled.
// Saved table views preserve captures before state/argument stores and later code-word reads.
struct NativeActorControlVtable
{
    byte unmodeledBeforeCheckAnimFinished[0xe4];
    uint checkAnimFinishedAddress;
    byte unmodeledBeforeSetPhysics[52];
    uint setPhysicsAddress;
    byte unmodeledBeforePlayAnim[64];
    uint playAnimAddress;
};
