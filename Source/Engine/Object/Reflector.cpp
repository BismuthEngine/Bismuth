#include "Reflector.h"

template<BismuthClass _ClassTrait>
inline TReflector_Class_Registration_Wrapper<_ClassTrait>::TReflector_Class_Registration_Wrapper()
{
	WrappedObj = new _ClassTrait();
}
