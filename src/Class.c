#include <stddef.h>
#include "Class.h"

Class Class_Class = {NULL};

int InstanceOf(void* object, const Class* class)
{
    const Class* _class;

    _class = ((Class*)object)->super;
    if(!class)
    {
        return 1;
    }
    else
    {
        while(_class)
        {
            if(_class == class)
            {
                return 1;
            }
            _class = _class->super;
        }

        return 0;
    }
}
