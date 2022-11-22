#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <complex.h>
#include "IObject.h"
#include "Object.h"
#include "Basic.h"

void* _Short_New(void* implementor)
{
    return malloc(sizeof(short));
}

void* _Short_Del(void* implementor)
{
    free(implementor);

    return NULL;
}

int _Short_Copy(void* implementor, void* object)
{
    short* num1,* num2;
    
    num1 = (short*)implementor;
    num2 = (short*)object;
    *(num1) = *(num2);
    
    return 1;
}

int _Short_Equal(void* implementor, void* object)
{
    short* num1,* num2;
    
    num1 = (short*)implementor;
    num2 = (short*)object;
    if(*(num1) == *(num2))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void* _Int_New(void* implementor)
{
    return malloc(sizeof(int));
}

void* _Int_Del(void* implementor)
{
    free(implementor);

    return NULL;
}

int _Int_Copy(void* implementor, void* object)
{
    int* num1,* num2;
    
    num1 = (int*)implementor;
    num2 = (int*)object;
    *(num1) = *(num2);

    return 1;
}

int _Int_Equal(void* implementor, void* object)
{
    int* num1,* num2;
    
    num1 = (int*)implementor;
    num2 = (int*)object;
    if(*(num1)==*(num2))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void* _Long_New(void* implementor)
{
    return malloc(sizeof(long));
}

void* _Long_Del(void* implementor)
{
    free(implementor);

    return NULL;
}

int _Long_Copy(void* implementor, void* object)
{
    long* num1,* num2;
    
    num1 = (long*)implementor;
    num2 = (long*)object;
    *(num1) = *(num2);

    return 1;
}

int _Long_Equal(void* implementor, void* object)
{
    long* num1,* num2;
    
    num1 = (long*)implementor;
    num2 = (long*)object;
    if(*(num1) == *(num2))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void* _Float_New(void* implementor)
{
    return malloc(sizeof(float));
}

void* _Float_Del(void* implementor)
{
    free(implementor);

    return NULL;
}

int _Float_Copy(void* implementor, void* object)
{
    float* num1,* num2;
    
    num1 = (float*)implementor;
    num2 = (float*)object;
    *(num1) = *(num2);

    return 1;
}

int _Float_Equal(void* implementor, void* object)
{
    float* num1,* num2;
    
    num1 = (float*)implementor;
    num2 = (float*)object;
    if(*(num1)==*(num2))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void* _Double_New(void* implementor)
{
    return malloc(sizeof(double));
}

void* _Double_Del(void* implementor)
{
    free(implementor);

    return NULL;
}

int _Double_Copy(void* implementor, void* object)
{
    double* num1,* num2;
    
    num1 = (double*)implementor;
    num2 = (double*)object;
    *(num1) = *(num2);

    return 1;
}

int _Double_Equal(void* implementor, void* object)
{
    double* num1,* num2;
    
    num1 = (double*)implementor;
    num2 = (double*)object;
    if(*(num1)==*(num2))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void* _Float_Complex_New(void* implementor)
{
    return malloc(sizeof(float complex));
}

void* _Float_Complex_Del(void* implementor)
{
    free(implementor);

    return NULL;
}

int _Float_Complex_Copy(void* implementor, void* object)
{
    float complex* num1,* num2;
    
    num1 = (float complex*)implementor;
    num2 = (float complex*)object;
    *(num1) = *(num2);

    return 1;
}

int _Float_Complex_Equal(void* implementor, void* object)
{
    float complex* num1,* num2;
    
    num1 = (float complex*)implementor;
    num2 = (float complex*)object;
    if(*(num1)==*(num2))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void* _Double_Complex_New(void* implementor)
{
    return malloc(sizeof(double complex));
}

void* _Double_Complex_Del(void* implementor)
{
    free(implementor);

    return NULL;
}

int _Double_Complex_Copy(void* implementor, void* object)
{
    double complex* num1,* num2;
    
    num1 = (double complex*)implementor;
    num2 = (double complex*)object;
    *(num1) = *(num2);

    return 1;
}

int _Double_Complex_Equal(void* implementor, void* object)
{
    double complex* num1,* num2;
    
    num1 = (double complex*)implementor;
    num2 = (double complex*)object;
    if(*(num1)==*(num2))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void* _Char_New(void* implementor)
{
    return malloc(sizeof(char));
}

void* _Char_Del(void* implementor)
{
    free(implementor);

    return NULL;
}

int _Char_Copy(void* implementor, void* object)
{
    char* char1,* char2;
    
    char1 = (char*)implementor;
    char2 = (char*)object;
    *(char1) == *(char2);

    return 1;
}

int _Char_Equal(void* implementor, void* object)
{
    char* char1,*char2;
    
    char1 = (char*)implementor;
    char2 = (char*)object;
    if(*(char1)==*(char2))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void* _String_New(void* implementor)
{
    char* string;
    
    string = (char*)malloc(sizeof(char)*100);
    *(string) = '\0';
    
    return string;
}

void* _String_Del(void* implementor)
{
    free(implementor);

    return NULL;
}

int _String_Copy(void* implementor, void* object)
{
    int len;
    
    len = strlen((char*)object);
    if(len>100)
    {
        printf("The len of object is bigger than 100\n");
        
        return 0;
    }
    memcpy(implementor, object, sizeof(char)*100);

    return 1;
}

int _String_Equal(void* implementor, void* object)
{
    if(memcmp(implementor, object, sizeof(char)*100))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void* _Pointer_New(void* implementor)
{
    return malloc(sizeof(void*));
}

void* _Pointer_Del(void* implementor)
{
    free(implementor);
    
    return NULL;
}

int _Pointer_Copy(void* implementor, void* object)
{
    void** pointer1,** pointer2;
    
    pointer1 = (void**)implementor;
    pointer2 = (void**)object;
    *(pointer1) = *(pointer2);

    return 1;
}

int _Pointer_Equal(void* implementor, void* object)
{
    void** pointer1,** pointer2;
    
    pointer1 = (void**)implementor;
    pointer2 = (void**)object;
    if(*(pointer1) == *(pointer2))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

IObject _Short = {NULL, _Short_New, _Short_Del, _Short_Copy, _Short_Equal};
IObject _Int = {NULL, _Int_New, _Int_Del, _Int_Copy, _Short_Equal};
IObject _Float = {NULL, _Float_New, _Float_Del, _Float_Copy, _Float_Equal};
IObject _Double = {NULL, _Double_New, _Double_Del, _Double_Copy, _Double_Equal};
IObject _Float_Complex = {NULL, _Float_Complex_New, _Float_Complex_Del, _Float_Complex_Copy, _Float_Complex_Equal};
IObject _Double_Complex = {NULL, _Double_Complex_New, _Double_Complex_Del, _Double_Complex_Copy, _Double_Complex_Equal};
IObject _Char = {NULL, _Char_New, _Char_Del, _Char_Copy, _Char_Equal};
IObject _String = {NULL, _String_New, _String_Del, _String_Copy, _String_Equal};
IObject _Pointer = {NULL, _Pointer_New, _Pointer_Del, _Pointer_Copy, _Pointer_Equal};

IObject* Short = &_Short;
IObject* Int = &_Int;
IObject* Float = &_Float;
IObject* Double = &_Double;
IObject* Float_Complex = &_Float_Complex;
IObject* Double_Complex = &_Double_Complex;
IObject* Char = &_Char;
IObject* String = &_String;
IObject* Pointer = &_Pointer;
