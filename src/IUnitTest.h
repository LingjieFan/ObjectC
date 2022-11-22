#ifndef _IUNITTEST_H_
#define _INUITTEST_H_

typedef struct _IUnitTest IUnitTest;

struct _IUnitTest
{
    void* implementor;
    void (*TestAll)(void* implementor);
};

extern void IUnitTest_TestAll(IUnitTest* this);

#endif /*_INUITTEST_H_*/