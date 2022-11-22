#ifndef _UNITTEST_IOBJECT_H_
#define _UNITTEST_IOBJECT_H_

#define UNITTEST_IOBJECT &UnitTest_IObject_Class

typedef struct _Class Class;
typedef struct _IUnitTest IUnitTest;
typedef struct _UnitTest_IObject UnitTest_IObject;

extern Class UnitTest_IObject_Class;

extern UnitTest_IObject* UnitTest_IObject_New();

extern UnitTest_IObject* UnitTest_IObject_Del(UnitTest_IObject* this);

extern IUnitTest* UnitTest_IObject_GetIUnitTest(UnitTest_IObject* this);

extern void UnitTest_IObject_TestAll(UnitTest_IObject* this);

#endif /*_UNITTEST_IOBJECT_H_*/