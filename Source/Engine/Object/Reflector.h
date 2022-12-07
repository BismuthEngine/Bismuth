#pragma once

#include "Concepts.h"

template <BismuthClass _ClassTrait>
struct TReflector_Trait {
	static class NClass* DefaultClassObject;
};

template <BismuthClass _ClassTrait>
class TReflector_Class_Registration_Wrapper {
	class NClass* WrappedObj;
public:
	TReflector_Class_Registration_Wrapper();

	NClass* Get() { return WrappedObj; }
};

class TReflector {
public:
	NClass* s;
};

