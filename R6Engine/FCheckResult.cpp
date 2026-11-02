// R6Engine.dll @ 10001750 : InitializeCheckResult
// Initializes a linked collision result and preserves the supplied time bits.
FCheckResult* __thiscall InitializeCheckResult(FCheckResult* result, float initialTime,
    FCheckResult* next)
{
    // Both argument words are captured before any result writes.
    uint timeBits = reinterpret_cast<const uint&>(initialTime);
    FCheckResult* nextResult = next;
    result->Next = nextResult;
    result->Actor = nullptr;
    result->Location.X = 0.0f;
    result->Location.Y = 0.0f;
    result->Location.Z = 0.0f;
    result->Normal.X = 0.0f;
    result->Normal.Y = 0.0f;
    result->Normal.Z = 0.0f;
    result->Primitive = nullptr;
    reinterpret_cast<uint&>(result->Time) = timeBits; // Native MOV; no floating conversion.
    result->Item = -1;
    result->Material = nullptr;
    return result;
}
