# ObjectC

![pureC](https://img.shields.io/github/languages/top/LingjieFan/ObjectC)
[![license](https://img.shields.io/github/license/LingjieFan/ObjectC)](https://github.com/LingjieFan/ObjectC/blob/main/LICENSE)
[![tag](https://img.shields.io/github/v/tag/LingjieFan/ObjectC)](https://github.com/LingjieFan/ObjectC/releases/tag)
[![issue](https://img.shields.io/github/issues/LingjieFan/ObjectC)](https://github.com/LingjieFan/ObjectC/issues)

ObjectC is a C library for object-oriented programming (OOP) features without any new features. Add OOP features to C! No macro definition! No new syntax! Only C.

Key features for object-oriented programming (OOP) are included:

* Supporting single-inheritance class-based object-oriented model.
* Supporting multiple inheritance of interfaces.

More repositories are built on ObjectC with object-oriented features but pure C syntax.

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
gcc -shared -fPIC Basic.o Class.o IObject.o Object.o IUnitTest.o -o ObjectC.os
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

MSCV is not recommended, since some C synatxes in C99, such as double complex, are not supported by MSCV. 

## Documentation

## Contact us

Author: Lingjie Fan (A student of Fudan University)

Email: 20210190044@fudan.edu.cn
