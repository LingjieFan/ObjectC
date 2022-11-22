#ifndef _CLASS_H_
#define _CLASS_H_

#define CLASS &Class_Class

typedef struct _Class Class;

struct _Class
{
    Class* super;
};

extern Class Class_Class;

extern int InstanceOf(void* object, const Class* class);

#endif /*_CLASS_H_*/