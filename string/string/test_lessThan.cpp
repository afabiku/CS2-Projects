#include "string.hpp"
#include <cassert>
#include <iostream>

int main() {

    {
        String str1("apple");
        String str2("banana");
        assert(str1 < str2);
    }

    {
        String str1("apple");
        String str2("app");
        assert(!(str1 < str2));
    }

    {
        String str1("hello");
        String str2("hello");
        assert(!(str1 < str2));
    }


    {
        const char array[] = "apple";
        String str("banana");
        assert(array < str);
    }

    {
        const char array[] = "apple";
        String str("apple");
        assert(!(array < str));
    }

    {
        const char array[] = "apple";
        String str("");
        assert(!(array < str));
    }


    {
        char singleChar = 'A';
        String str("B");
        assert(singleChar < str);
    }

    {
        char singleChar = 'B';
        String str("A");
        assert(!(singleChar < str));
    }

    {
        char singleChar = 'A';
        String str("");
        assert(!(singleChar < str));
    }

    std::cout << "All tests passed." << std::endl;
    return 0;
}
