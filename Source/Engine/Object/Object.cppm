export module Object;

#include "Object.h"
#include "Reflector.h"

template <> NClass* TReflector_Trait<NObject>::DefaultClassObject = (new TReflector_Class_Registration_Wrapper<NObject>())->Get();