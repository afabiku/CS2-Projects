#include "string.hpp"
#include <cassert>
#include <iostream>

int main() {
    {
        String str1("");
        String str2("hello");
        str1 += str2;
        assert(str1 == "hello");
    }

    {
        String str1;
        String str2;
        str1 += str2;
        assert(str1 == "");
    }

    {
        String str1("apple");
        String str2("banana");
        str1 += str2;
        assert(str1 == "applebanana");
    }

    {
        String str("hello");
        str += str;
        assert(str == "hellohello");
    }


    {
        String str1("");
        String str2("");
        String result = str1 + str2;
        assert(result == "");
    }

    {
        String str1("");
        String str2("world");
        String result = str1 + str2;
        assert(result == "world");
    }

    {
        String str1("hello");
        String str2("world");
        String result = str1 + str2;
        assert(result == "helloworld");
    }

    std::cout << "All tests passed." << std::endl;
    return 0;
}
