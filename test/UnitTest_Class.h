#ifndef _UNITTEST_CLASS_H_
#define _UNITTEST_CLASS_H_

#define UNITTEST_CLASS &UnitTest_Class_Class

typedef struct _Class Class;
typedef struct _IUnitTest IUnitTest;
typedef struct _UnitTest_Class UnitTest_Class;

extern Class UnitTest_Class_Class;

extern UnitTest_Class* UnitTest_Class_New();

extern UnitTest_Class* UnitTest_Class_Del(UnitTest_Class* this);

extern IUnitTest* UnitTest_Class_GetIUnitTest(UnitTest_Class* this);

extern void UnitTest_Class_TestAll(UnitTest_Class* this);

#endif /*_UNITTEST_CLASS_H_*/
