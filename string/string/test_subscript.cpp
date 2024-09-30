#include "string.hpp"
#include <cassert>
#include <iostream>

int main() {

    {
        String str("hello");
        char& firstChar = str[0];
        assert(firstChar == 'h');
    }

    {
        String str("hello");
        char& lastChar = str[4];
        assert(lastChar == 'o');
    }

    {
        String str("hello");
        str[0] = 'H';
        assert(str == "Hello");
    }


    {
        const String str("hello");
        char firstChar = str[0];
        assert(firstChar == 'h');
    }

    {
        const String str("hello");
        char lastChar = str[4];
        assert(lastChar == 'o');
    }

    {
        const String str("hello");
        assert(str[0] == 'h');
    }

    std::cout << "All tests passed." << std::endl;
    return 0;
}
