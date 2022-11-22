#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "Class.h"
#include "Object.h"
#include "IObject.h"
#include "IUnitTest.h"
#include "UnitTest_Object.h"

Class UnitTest_Object_Class = {CLASS};

struct _UnitTest_Object
{
    Class* class;
    IUnitTest* iUnitTest;
};

void _UnitTest_Object_TestAll(void* implementor);

struct _Object
{
    Class* class;
    IObject* iObject;
};

void* _Stub_Object_New(void* implementor)
{
    return (void*)0;
}

void* _Stub_Object_Del(void* implementor)
{
    return (void*)1;
}

int _Stub_Object_Copy(void* implementor, void* object)
{
    return 2;
}

int _Stub_Object_Equal(void* implementor, void* object)
{
    return 3;
}

void Test_Object_Correct_Function_Pointer()
{
    int result;
    IObject sub_iObject = {NULL, _Stub_Object_New, _Stub_Object_Del, _Stub_Object_Copy, _Stub_Object_Equal};
    Object sub_object = {NULL, &sub_iObject};
    
    result = (int)Object_New(&sub_object);
    assert(result == 0);
    result = (int)Object_Del(&sub_object);
    assert(result == 1);
    result = Object_Copy(&sub_object, NULL);
    assert(result == 2);
    result = Object_Equal(&sub_object, NULL);
    assert(result == 3);
    printf("Test_Object_Correct_Function_Pointer Success.\n");
}

UnitTest_Object* UnitTest_Object_New()
{
    UnitTest_Object* unit_test;
    
    unit_test = (UnitTest_Object*)malloc(sizeof(UnitTest_Object)+sizeof(IUnitTest));
    unit_test->class = UNITTEST_OBJECT;
    unit_test->iUnitTest = (IUnitTest*)(unit_test+1);
    unit_test->iUnitTest->implementor = unit_test;
    unit_test->iUnitTest->TestAll = _UnitTest_Object_TestAll;
    
    return unit_test;
}

UnitTest_Object* UnitTest_Object_Del(UnitTest_Object* this)
{
    free(this);
    
    return NULL;
}

IUnitTest* UnitTest_Object_GetIUNitTest(UnitTest_Object* this)
{
    return this->iUnitTest;
}

void UnitTest_Object_TestAll(UnitTest_Object* this)
{
    Test_Object_Correct_Function_Pointer();
}

void _UnitTest_Object_TestAll(void* implementor)
{
    UnitTest_Object* unit_test;
    
    unit_test = (UnitTest_Object*)implementor;
    UnitTest_Object_TestAll(unit_test);
}
