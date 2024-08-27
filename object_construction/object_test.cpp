#include "object_construction.hpp"

MyClass::MyClass() {
    std::cout << "Called Default Constructor" << std::endl;
    value = 0;
}

MyClass::MyClass(const MyClass& input) {
    std::cout << "Called Copy Constructor" << std::endl;
    value = input.value;
}

MyClass& MyClass::operator=(const MyClass& input) {
    std::cout << "Called Assignment Operator" << std::endl;
    if (this != &input) {
        value = input.value;
    }
    return *this;
}

MyClass::~MyClass() {
    std::cout << "Called Destructor" << std::endl;
}

int main() {
    std::cout << "Creating obj1" << std::endl;
    MyClass obj1;

    std::cout << "Creating obj2" << std::endl;
    MyClass obj2;

    std::cout << "Assigning obj2 to obj1" << std::endl;
    obj1 = obj2;

    std::cout << "Creating obj3 and assigning it obj1" << std::endl;
    MyClass obj3 = obj1;

    std::cout << "Exiting main" << std::endl;

    return 0;
}