#ifndef _UNITTEST_BASIC_H_
#define _UNITTEST_BASIC_H_

#define UNITTEST_BASIC &UnitTest_Basic_Class

typedef struct _Class Class;
typedef struct _IUnitTest IUnitTest;
typedef struct _UnitTest_Basic UnitTest_Basic;

extern Class UnitTest_Basic_Class;

extern UnitTest_Basic* UnitTest_Basic_New();

extern UnitTest_Basic* UnitTest_Basic_Del(UnitTest_Basic* this);

extern IUnitTest* UnitTest_Basic_GetIUnitTest(UnitTest_Basic* this);

extern void UnitTest_Basic_TestAll(UnitTest_Basic* this);

#endif /*_UNITTEST_BASIC_H_*/