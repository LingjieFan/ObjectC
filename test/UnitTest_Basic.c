#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Class.h"
#include "IUnitTest.h"
#include "Basic.h"
#include "IObject.h"
#include "UnitTest_Basic.h"

Class UnitTest_Basic_Class = {CLASS};

struct _UnitTest_Basic
{
    Class* class;
    IUnitTest* iUnitTest;
};

void _UnitTest_Basic_TestAll(void* implementor);

void Test_Short_IObject()
{
    int size, result;
    short num;
    short* new_object;

    num = 0;
    new_object = (short*)IObject_New(Short);
    assert(new_object != NULL);
    Short->implementor = new_object;
    size = sizeof(*new_object);
    assert(size == sizeof(short));
    num = 4;
    IObject_Copy(Short, &num);
    assert(*(new_object) == 4);
    result = IObject_Equal(Short, &num);
    assert(result == 1);
    num = 0;
    result = IObject_Equal(Short, &num);
    assert(result == 0);
    Short->implementor = NULL;
    new_object = (short*)IObject_Del(Short);
    assert(new_object == NULL);
    printf("Test_Short_IObject Success.\n");
}

void Test_Basic_Pointer_New()
{
    void** pointer;
    
    pointer = (void**)IObject_New(Pointer);
    assert(pointer != NULL);
    printf("Test_Basic_Pointer_New Success.\n");
}

UnitTest_Basic* UnitTest_Basic_New()
{
    UnitTest_Basic* unit_test;
    
    unit_test = (UnitTest_Basic*)malloc(sizeof(UnitTest_Basic)+sizeof(IUnitTest));
    unit_test->class = UNITTEST_BASIC;
    unit_test->iUnitTest = (IUnitTest*)(unit_test+1);
    unit_test->iUnitTest->implementor = unit_test;
    unit_test->iUnitTest->TestAll = _UnitTest_Basic_TestAll;
    
    return unit_test;
}

UnitTest_Basic* UnitTest_Basic_Del(UnitTest_Basic* this)
{
    free(this);
    
    return NULL;
}

IUnitTest* UnitTest_Basic_GetIUnitTest(UnitTest_Basic* this)
{
    return this->iUnitTest;
}

void UnitTest_Basic_TestAll(UnitTest_Basic* this)
{
    Test_Short_IObject();
    Test_Basic_Pointer_New();
}

void _UnitTest_Basic_TestAll(void* implementor)
{
    UnitTest_Basic* unit_test;
    
    unit_test = (UnitTest_Basic*)implementor;
    UnitTest_Basic_TestAll(unit_test);
}
