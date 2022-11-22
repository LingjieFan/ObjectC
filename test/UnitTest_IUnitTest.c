#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Class.h"
#include "IUnitTest.h"
#include "UnitTest_IUnitTest.h"

Class UnitTest_IUnitTest_Class = {CLASS};

struct _UnitTest_IUnitTest
{
    Class* class;
    IUnitTest* iUnitTest;
};

void _UnitTest_IUnitTest_TestAll(void* implementor);

void _Stub_IUnitTest_TestAll(void* implementor)
{
    
}

void Test_IUnitTest_Correct_Function_Pointer()
{
    IUnitTest stub_iUnitTest = {NULL, _Stub_IUnitTest_TestAll};
    
    assert(stub_iUnitTest.TestAll == _Stub_IUnitTest_TestAll);
    printf("Test_IUnitTest_Correct_Function_Pointer Success.\n");
}

UnitTest_IUnitTest* UnitTest_IUnitTest_New()
{
    UnitTest_IUnitTest* unit_test;
    
    unit_test = (UnitTest_IUnitTest*)malloc(sizeof(UnitTest_IUnitTest)+sizeof(IUnitTest));
    unit_test->class = UNITTEST_IUNITTEST;
    unit_test->iUnitTest = (IUnitTest*)(unit_test+1);
    unit_test->iUnitTest->implementor = unit_test;
    unit_test->iUnitTest->TestAll = _UnitTest_IUnitTest_TestAll;
    
    return unit_test;
}

UnitTest_IUnitTest* UnitTest_IUnitTest_Del(UnitTest_IUnitTest* this)
{
    free(this);
    
    return NULL;
}

IUnitTest* UnitTest_IUnitTest_GetIUnitTest(UnitTest_IUnitTest* this)
{
    return this->iUnitTest;
}

void UnitTest_IUnitTest_TestAll(UnitTest_IUnitTest* this)
{
    Test_IUnitTest_Correct_Function_Pointer();
}

void _UnitTest_IUnitTest_TestAll(void* implementor)
{
    UnitTest_IUnitTest* unit_test;
    
    unit_test = (UnitTest_IUnitTest*)implementor;
    UnitTest_IUnitTest_TestAll(unit_test);
}
