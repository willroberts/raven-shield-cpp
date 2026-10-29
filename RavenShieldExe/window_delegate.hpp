#pragma once

// Native Window.dll delegates use a vptr at +0, target at +4 and one-word member-function pointer at +8.
class __single_inheritance FCommandTarget;
using TDelegate = void (FCommandTarget::*)();
struct __declspec(dllimport) FDelegate
{
  FCommandTarget *TargetObject;
  TDelegate TargetInvoke;
  FDelegate(FCommandTarget *target, TDelegate invoke);
  FDelegate(const FDelegate &other);
  virtual void operator()();
};
