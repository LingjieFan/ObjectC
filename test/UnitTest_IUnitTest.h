#ifndef _UNITTEST_IUNITTEST_H_
#define _UNITTEST_IUNITTEST_H_

#define UNITTEST_IUNITTEST &UnitTest_IUnitTest_Class

typedef struct _Class Class;
typedef struct _IUnitTest IUnitTest;
typedef struct _UnitTest_IUnitTest UnitTest_IUnitTest;

extern Class UnitTest_IUnitTest_Class;

extern UnitTest_IUnitTest* UnitTest_IUnitTest_New();

extern UnitTest_IUnitTest* UnitTest_IUnitTest_Del(UnitTest_IUnitTest* this);

extern IUnitTest* UnitTest_IUnitTest_GetIUnitTest(UnitTest_IUnitTest* this);

extern void UnitTest_IUnitTest_TestAll(UnitTest_IUnitTest* this);

#endif /*_UNITTEST_IUNITTEST_H_*/