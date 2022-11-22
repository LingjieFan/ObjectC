#include <stdlib.h>
#include "Class.h"
#include "IUnitTest.h"
#include "UnitTest_Class.h"
#include "UnitTest_IObject.h"
#include "UnitTest_IUnitTest.h"
#include "UnitTest_Object.h"
#include "UnitTest_ObjectC.h"
#include "UnitTest_Basic.h"

Class UnitTest_ObjectC_Class = {CLASS};

struct _UnitTest_ObjectC
{
    Class* class;
    IUnitTest* iUnitTest;
    UnitTest_Class* unitTest_class;
    UnitTest_IObject* unitTest_iObject;
    UnitTest_IUnitTest* unitTest_iUnitTest;
    UnitTest_Object* unitTest_object;
    UnitTest_Basic* unitTest_basic;
};

void _UnitTest_ObjectC_TestAll(void* implementor);

UnitTest_ObjectC* UnitTest_ObjectC_New()
{
    UnitTest_ObjectC* unit_test;
    
    unit_test = (UnitTest_ObjectC*)malloc(sizeof(UnitTest_ObjectC)+sizeof(IUnitTest));
    unit_test->class = UNITTEST_OBJECTC;
    unit_test->iUnitTest = (IUnitTest*)(unit_test+1);
    unit_test->iUnitTest->implementor = unit_test;
    unit_test->iUnitTest->TestAll = _UnitTest_ObjectC_TestAll;
    unit_test->unitTest_class = UnitTest_Class_New();
    unit_test->unitTest_iObject = UnitTest_IObject_New();
    unit_test->unitTest_iUnitTest = UnitTest_IUnitTest_New();
    unit_test->unitTest_object = UnitTest_Object_New();
    unit_test->unitTest_basic = UnitTest_Basic_New();
    
    return unit_test;
}

UnitTest_ObjectC* UnitTest_ObjectC_Del(UnitTest_ObjectC* this)
{
    UnitTest_Class_Del(this->unitTest_class);
    UnitTest_IObject_Del(this->unitTest_iObject);
    UnitTest_IUnitTest_Del(this->unitTest_iUnitTest);
    UnitTest_Object_Del(this->unitTest_object);
    UnitTest_Basic_Del(this->unitTest_basic);
    free(this);
    
    return NULL;
}

IUnitTest* UnitTest_ObjectC_GetIUnitTest(UnitTest_ObjectC* this)
{
    return this->iUnitTest;
}

void UnitTest_ObjectC_TestAll(UnitTest_ObjectC* this)
{
    UnitTest_Class_TestAll(this->unitTest_class);
    UnitTest_IObject_TestAll(this->unitTest_iObject);
    UnitTest_IUnitTest_TestAll(this->unitTest_iUnitTest);
    UnitTest_Object_TestAll(this->unitTest_object);
    UnitTest_Basic_TestAll(this->unitTest_basic);
}

void _UnitTest_ObjectC_TestAll(void* implementor)
{
    UnitTest_ObjectC* unit_test;

    unit_test = (UnitTest_ObjectC*)implementor;
    UnitTest_ObjectC_TestAll(unit_test);
}