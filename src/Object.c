#include "Object.h"
#include "Class.h"
#include "IObject.h"

Class Object_Class = {CLASS};

struct _Object
{
    Class* class;
    IObject* iObject;
};

Object* Object_New(Object* this)
{
    return (Object*)(*this->iObject->New)(this);
}

Object* Object_Del(Object* this)
{
    return (Object*)(*this->iObject->Del)(this);
}

int Object_Copy(Object* this, void* object)
{
    return (*this->iObject->Copy)(this, object);
}

int Object_Equal(Object* this, void* object)
{
    return (*this->iObject->Equal)(this, object);
}
