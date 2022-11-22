#ifndef _UNITTEST_OBJECT_H_
#define _UNITTEST_OBJECT_H_

#define UNITTEST_OBJECT &UnitTest_Object_Class;

typedef struct _Class Class;
typedef struct _IUnitTest IUnitTest;
typedef struct _UnitTest_Object UnitTest_Object;

extern Class UnitTest_Object_Class;

extern UnitTest_Object* UnitTest_Object_New();

extern UnitTest_Object* UnitTest_Object_Del(UnitTest_Object* this);

extern IUnitTest* UnitTest_Object_GetIUnitTest(UnitTest_Object* this);

extern void UnitTest_Object_TestAll(UnitTest_Object* this);

#endif /*_UNITTEST_OBJECT_H_*/