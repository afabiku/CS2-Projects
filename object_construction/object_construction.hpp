#ifndef OBJECT_CONSTRUCTION
#define OBJECT_CONSTRUCTION
#include <iostream>
class MyClass {
public:
    MyClass();  
    MyClass(const MyClass&); 
    MyClass& operator=(const MyClass&); 
    ~MyClass();  
private:
    int value;
};
#endif