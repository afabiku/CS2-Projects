#include "string.hpp"
#include <cassert>
#include <iostream>

int main() {
    {
        char singleChar = 'X';
        String str(singleChar);
        assert(str == "X");
        assert(str.length() == 1);
    }

    {
        char singleChar = 'a';
        String str(singleChar);
        assert(str == "a");
        assert(str.length() == 1);
    }

    {
        char singleChar = '5';
        String str(singleChar);
        assert(str == "5");
        assert(str.length() == 1);
    }

    {
        char singleChar = '@';
        String str(singleChar);
        assert(str == "@");
        assert(str.length() == 1);
    }

    {
        char singleChar = '\0';
        String str(singleChar);
        assert(str == "");
        assert(str.length() == 0);
    }

    std::cout << "All tests passed." << std::endl;
    return 0;
}
