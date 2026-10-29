#include "native_symbols.hpp"
// Pool-node list operations; the specialization spelling is corroborated by UE2, with native links at +18/+1c.
#include "launch_runtime.hpp"

// RavenShield.exe @ 10904af0 : TDoubleLinkedList<FMallocWindows::FPoolInfoBase>::Unlink
// Remove this node by repairing its successor's back-link and the preceding link slot; retain this node's links.
template <> void TDoubleLinkedList<FMallocWindows::FPoolInfoBase>::Unlink()
{
  if (Next != nullptr) Next->PrevLink = PrevLink;
  *PrevLink = Next;
}

// RavenShield.exe @ 10904b10 : TDoubleLinkedList<FMallocWindows::FPoolInfoBase>::Link
// Insert before the referenced head, reloading that head after repairing the old head's back-link.
template <> void TDoubleLinkedList<FMallocWindows::FPoolInfoBase>::Link(TDoubleLinkedList *&before)
{
  if (before != nullptr) before->PrevLink = &Next;
  Next = before;
  PrevLink = &before;
  before = this;
}
