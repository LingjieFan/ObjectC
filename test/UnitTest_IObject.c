#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Class.h"
#include "IUnitTest.h"
#include "IObject.h"
#include "UnitTest_IObject.h"

Class UnitTest_IObject_Class = {CLASS};

struct _UnitTest_IObject
{
    Class* class;
    IUnitTest* iUnitTest;
};

void _UnitTest_IObject_TestAll(void* implementor);

void* _Stub_IObject_New(void* implementor)
{
    return (void*)0;
}

void* _Stub_IObject_Del(void* implementor)
{
    return (void*)1;
}

int _Stub_IObject_Copy(void* implementor, void* object)
{
    return 2;
}

int _Stub_IObject_Equal(void* implementor, void* object)
{
    return 3;
}

void Test_IObject_Correct_Function_Pointer()
{
    int result;
    IObject stub_iObject = {NULL, _Stub_IObject_New, _Stub_IObject_Del, _Stub_IObject_Copy, _Stub_IObject_Equal};
    
    result = (int)IObject_New(&stub_iObject);
    assert(result == 0);
    result = (int)IObject_Del(&stub_iObject);
    assert(result == 1);
    result = IObject_Copy(&stub_iObject, NULL);
    assert(result == 2);
    result = IObject_Equal(&stub_iObject, NULL);
    assert(result == 3);
    printf("Test_IObject_Correct_Function_Pointer Success.\n");
}

UnitTest_IObject* UnitTest_IObject_New()
{
    UnitTest_IObject* unit_test;
    
    unit_test = (UnitTest_IObject*)malloc(sizeof(UnitTest_IObject)+sizeof(IUnitTest));
    unit_test->class = UNITTEST_IOBJECT;
    unit_test->iUnitTest = (IUnitTest*)(unit_test+1);
    unit_test->iUnitTest->implementor = unit_test;
    unit_test->iUnitTest->TestAll = _UnitTest_IObject_TestAll;

    return unit_test;
}

UnitTest_IObject* UnitTest_IObject_Del(UnitTest_IObject* this)
{
    free(this);
    
    return NULL;
}

IUnitTest* UnitTest_IObject_GetIUnitTest(UnitTest_IObject* this)
{
    return this->iUnitTest;
}

void UnitTest_IObject_TestAll(UnitTest_IObject* this)
{
    Test_IObject_Correct_Function_Pointer();
}

void _UnitTest_IObject_TestAll(void* implementor)
{
    UnitTest_IObject* unit_test;
    
    unit_test = (UnitTest_IObject*)implementor;
    UnitTest_IObject_TestAll(unit_test);
}
