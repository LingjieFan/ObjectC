#include "IUnitTest.h"
#include "UnitTest_ObjectC.h"

int main()
{
    UnitTest_ObjectC* unit_test;
    IUnitTest* iUnitTest;
    
    unit_test = UnitTest_ObjectC_New();
    iUnitTest = UnitTest_ObjectC_GetIUnitTest(unit_test);
    IUnitTest_TestAll(iUnitTest);
    UnitTest_ObjectC_Del(unit_test);
    
    return 0;
}