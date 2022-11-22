#include "IUnitTest.h"

void IUnitTest_TestAll(IUnitTest* this)
{
    (*this->TestAll)(this->implementor);
}
