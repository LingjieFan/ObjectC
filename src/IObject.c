#include <stdlib.h>
#include "IObject.h"

void* IObject_New(IObject* this)
{
    return (*this->New)(this->implementor);
}

IObject* IObject_Del(IObject* this)
{
    return (IObject*)(*this->Del)(this->implementor);
}

int IObject_Copy(IObject* this, void* object)
{
    return (*this->Copy)(this->implementor, object);
}

int IObject_Equal(IObject* this, void* object)
{
    return (*this->Equal)(this->implementor, object);
}
