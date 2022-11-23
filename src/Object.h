#ifndef _OBJECT_H_
#define _OBJECT_H_

#define OBJECT &Object_Class

typedef struct _Class Class;
typedef struct _IObject IObject;
typedef struct _Object Object;

extern Class Object_Class;

extern Object* Object_New(Object* this);

extern Object* Object_Del(Object* this);

extern IObject* Object_GetIObject(Object* this);

extern int Object_Copy(Object* this, void* object);

extern int Object_Equal(Object* this, void* object);

#endif /*_OBJECT_H_*/
