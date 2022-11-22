#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "Class.h"
#include "IUnitTest.h"
#include "UnitTest_Class.h"

Class UnitTest_Class_Class = {CLASS};

struct _UnitTest_Class
{
    Class* class;
    IUnitTest* iUnitTest;
};

void _UnitTest_Class_TestAll(void* implementor);

void Test_InstanceOf_Chain()
{
    int result;
    Class class1 = {CLASS};
    Class class2 = {&class1};
    Class class3 = {&class2};
    Class class4 = {&class3};
    
    result = InstanceOf(&class4, &class3);
    assert(result == 1);
    result = InstanceOf(&class4, &class2);
    assert(result == 1);
    result = InstanceOf(&class4, &class1);
    assert(result == 1);
    result = InstanceOf(&class4, CLASS);
    assert(result == 1);
    result = InstanceOf(&class4, NULL);
    assert(result == 1);
    result = InstanceOf(CLASS, CLASS);
    assert(result == 0);
    result = InstanceOf(CLASS, &class1);
    assert(result == 0);
    result = InstanceOf(CLASS, &class2);
    assert(result == 0);
    result = InstanceOf(CLASS, &class3);
    assert(result == 0);
    result = InstanceOf(CLASS, &class4);
    assert(result == 0);
    printf("Test_InstanceOf_Chain Success.\n");
}

void Test_InstanceOf_Tree()
{
    int result;
    Class class1 = {CLASS};
    Class class2 = {CLASS};
    Class class3 = {&class1};
    Class class4 = {&class2};
    
    result = InstanceOf(&class4, &class1);
    assert(result == 0);
    result = InstanceOf(&class4, &class3);
    assert(result == 0);
    result = InstanceOf(&class2, &class1);
    assert(result == 0);
    printf("Test_InstanceOf_Tree Success.\n");    
}

UnitTest_Class* UnitTest_Class_New()
{
    UnitTest_Class* unit_test;
    
    unit_test = (UnitTest_Class*)malloc(sizeof(UnitTest_Class)+sizeof(IUnitTest));
    unit_test->class = UNITTEST_CLASS;
    unit_test->iUnitTest = (IUnitTest*)(unit_test+1);
    unit_test->iUnitTest->implementor = unit_test;
    unit_test->iUnitTest->TestAll = _UnitTest_Class_TestAll;
    
    return unit_test;
}

UnitTest_Class* UnitTest_Class_Del(UnitTest_Class* this)
{
    free(this);
    
    return NULL;
}

IUnitTest* UnitTest_Class_GetIUnitTest(UnitTest_Class* this)
{
    return this->iUnitTest;
}

void UnitTest_Class_TestAll(UnitTest_Class* this)
{
    Test_InstanceOf_Chain();
    Test_InstanceOf_Tree();
}

void _UnitTest_Class_TestAll(void* implementor)
{
    UnitTest_Class* unit_test;
    
    unit_test = (UnitTest_Class*)implementor;
    UnitTest_Class_TestAll(unit_test);
}
