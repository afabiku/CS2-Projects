#include "string.hpp"
#include <cassert>
#include <iostream>

int main() {
    {
        String str1("Hello");
        String str2("Hello");
        assert(str1 == str2);
    }

    {
        String str("Hello");
        const char array[] = "Hello";
        assert(str == array);
    }

    {
        String str('A');
        char singleChar = 'A';
        assert(str == singleChar);
    }

    {
        String str("Hello");
        const char array[] = "Hello";
        assert(array == str);
    }

    {
        String str('A');
        char singleChar = 'A';
        assert(singleChar == str);
    }



    std::cout << "All tests passed." << std::endl;
    return 0;
}
