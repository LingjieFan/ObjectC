# ObjectC

![pureC](https://img.shields.io/github/languages/top/LingjieFan/ObjectC)
![class](https://img.shields.io/github/search/LingjieFan/ObjectC/Class)
[![license](https://img.shields.io/github/license/LingjieFan/ObjectC)](https://github.com/LingjieFan/ObjectC/blob/main/LICENSE)
[![tag](https://img.shields.io/github/v/tag/LingjieFan/ObjectC)](https://github.com/LingjieFan/ObjectC/releases/tag)
[![issue](https://img.shields.io/github/issues/LingjieFan/ObjectC)](https://github.com/LingjieFan/ObjectC/issues)
![commit](https://img.shields.io/github/last-commit/LingjieFan/ObjectC)
![star](https://img.shields.io/github/stars/LingjieFan/ObjectC?style=social)
![watchers](https://img.shields.io/github/watchers/LingjieFan/ObjectC?style=social)

ObjectC is a C library for object-oriented programming (OOP) features. Add OOP features to C! No macro definition! No new syntax! Only C. **ObjectC is more like a coding standard for C**.

Key features for object-oriented programming (OOP) are included:

* Supporting single-inheritance class-based object-oriented model.
* Supporting multiple inheritance of interfaces.
* Supporting function InstanceOf() to determine whether the object is the stance of a class.
* Binding each class with a unique address, such as the root of all class is 'NULL' 0x00000000
* the attributes of a class is private, can only be accessed with getter/setter.
* Most important, No addition define macro, all syntax is pure C, ObjectC is more like a coding standard for C.

More repositories are built on ObjectC with object-oriented features but pure C syntax, such as:

1. [Container](https://github.com/LingjieFan/Container): Some Basic Data Structures: ArrayList, LinkedList, HashTable, Buffer(String) ... based on 'ObjectC'

2. [LinearC](https://github.com/LingjieFan/LinearC): A Linear library in C, a vector and matrix wrapper for blas and lapack, build on 'ObjectC'

## Installation

### Dependencies

* C compiler (gcc is used in the following examples)

### Linux

```cmd
gcc -c -fPIC Basic.c -o Basic.o
gcc -c -fPIC Class.c -o Class.o
gcc -c -fPIC IObject.c -o IObject.o
gcc -c -fPIC Object.c -o Object.o
gcc -c -fPIC IUnitTest.c -o IUnitTest.o
gcc -shared -fPIC Basic.o Class.o IObject.o Object.o IUnitTest.o -o libObjectC.so
```

### Windows

MinGW_32 or MinGW_64 is required for compiling the source codes. Once gcc is available, you can use following instructions in cmd to compile ObjectC.

```cmd
gcc -c -fPIC Basic.c -o Basic.o
gcc -c -fPIC Class.c -o Class.o
gcc -c -fPIC IObject.c -o IObject.o
gcc -c -fPIC Object.c -o Object.o
gcc -c -fPIC IUnitTest.c -o IUnitTest.o
gcc -shared -fPIC Basic.o Class.o IObject.o Object.o IUnitTest.o -o ObjectC.dll
```

Binary dynamic library files can be found [in the release](https://github.com/LingjieFan/ObjectC/releases/tag/v1.0.0).

MSCV is not recommended, since some C synatxes in C99, such as **double complex**, are not supported by MSCV. 

## Documentation

### The OOP features of ObjectC

As you can see in the following, no new syntax is introduced into C, OOP is estabished by using original syntax of C, like structure, function pointer, function.

#### Single inheritance

ObjectC supports single inheritance. Each class is binded with an address. The root of all classes is 'NULL', while the child class of 'NULL' is 'CLASS', as you can find a linked list in Class.h, Class.c, Object.h or Object.c files:

```C
#define CLASS &Class_Class     // in Class.h bind each class with an address

Class Class_Class = {NULL};   // in Class.h
```

```C
#define OBJECT &Object_Class   // in Object.h bind each class with an address

Class Object_Class = {CLASS}; // in Object.c
```

which means the parent class of 'Object' is 'Class', and the parent class of 'Class' is 'NULL' or 'VOID' type in C. 

Now, the inheritance chain is established in C, starting from 'NULL' to 'CLASS', next to 'OBJECT'. If you want to build some other classes with ObjectC, you can extend the inheritance chain by inherit the 'CLASS' or the 'OBJECT'. Please pay attention to make the members of the child structure in the same order of its parent class. like:

```C
struct _Object
{
    Class* class;
    IObject* iObject;
};  // in Object.c

```
The first memeber of struct _Object must be Class* class for inheriting from 'Class'. You should keep the members and their order be the same with its parent class. More example could be find here in other repositories build on ObjectC. 

#### Multiple interfaces
ObjectC supports multiple interfaces. Interfaces 'IObject' and 'IUnitTest' are contained in ObjectC. More interfaces examples could be found in repositories build on ObjectC. Unlike class, the C structure of interface should be place in the header files:

```C
struct _IObject
{
    void* implementor;
    void* (*New)(void* implementor);
    void* (*Del)(void* implementor);
    int (*Copy)(void* implementor, void* object);
    int (*Equal)(void* impelementor, void* object);
}; // in IObject.h
``` 

For Interface, the first element of C structure should be void* implementor to specify which class implements the interface. And the rest elements should be function pointers to specify the behaviors of this interface. Later, Interface could be included as attributes(elements) in class structure, such as

```C
struct _Object
{
    Class* class;
    IObject* iObject;
};
```

The class could implement the interface and expose it through a C function or it could recieve interface from other classes, such as

```C
IObject* Object_GetIObject(Object* this)
{
	return this->iObject;
} // expose its interface 'iObject' through a C function

extern ArrayList* ArrayList_New(IObject* iObjectContained); // recieve interface from other classes.
```

#### Other features

##### 1. InstanceOf()

ObjectC also support InstanceOf() function to judge whether an object belongs to a class. If it belongs to the class the function, the InstanceOf() function will return 1. Otherwise it returns 0. 

##### 2. Abstract class

'Object' in ObjectC is an abstract class since 'Object' implements interface 'IObject' but doesn't implement functions in it. The Class which isn't a abstract class and inherit 'Object' should implements interface 'IObject' and these functions.

#### 3. IUnitTest Interface

'IUnitTest' interface has been added into the ObjectC for unit test. Some examples for using 'IUnitTest' could be found in [test file folder](https://github.com/LingjieFan/ObjectC/tree/main/test)

## Contact us

Author: Lingjie Fan (A student from Fudan University)

Email: 20210190044@fudan.edu.cn
