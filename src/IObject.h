#ifndef _IOBJECT_H_
#define _IOBJECT_H_

typedef struct _IObject IObject;

struct _IObject
{
    void* implementor;
    void* (*New)(void* implementor);
    void* (*Del)(void* implementor);
    int (*Copy)(void* implementor, void* object);
    int (*Equal)(void* implementor, void* object);
};

extern void* IObject_New(IObject* this);

extern IObject* IObject_Del(IObject* this);

extern int IObject_Copy(IObject* this, void* object);

extern int IObject_Equal(IObject* this, void* object);

#endif /*_IOBJECT_H_*/
