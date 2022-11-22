#ifndef _UNITTEST_OBJECTC_H_
#define _UNITTEST_OBJECTC_H_

#define UNITTEST_OBJECTC &UnitTest_ObjectC_Class

typedef struct _Class Class;
typedef struct _IUnitTest IUnitTest;
typedef struct _UnitTest_ObjectC UnitTest_ObjectC;

extern Class UnitTest_ObjectC_Class;

extern UnitTest_ObjectC* UnitTest_ObjectC_New();

extern UnitTest_ObjectC* UnitTest_ObjectC_Del(UnitTest_ObjectC* this);

extern IUnitTest* UnitTest_ObjectC_GetIUnitTest(UnitTest_ObjectC* this);

extern void UnitTest_ObjectC_TestAll(UnitTest_ObjectC* this);

#endif /*_UNITTEST_OBJECTC_H_*/