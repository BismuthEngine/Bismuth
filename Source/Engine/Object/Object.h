#pragma once
#include "Class.h"
#include "ObjectMacros.h"
#include "Reflector.h"

CLASS(RefType)
class NObject : public NClass {
	CLASS_BODY()
protected:
	NClass* PrivateClass;

public:

	inline static NClass* StaticClass() { return TReflector_Trait<NObject>::DefaultClassObject; }
};

template <BismuthObject ObjectType>
ObjectType* CreateObject(NObject* owner);

template <BismuthObject ObjectType, BismuthObjectDerived<ObjectType> ChildClass = ObjectType>
ObjectType* CreateObject(NObject* owner, ChildClass* prototype);

//template <BismuthObject Obj, BismuthObjectDerived<Obj> DerivedClass>
//Obj* CreateObject(NObject owner, DerivedClass* prototype, String name);