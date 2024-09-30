#include "string.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main()
{
    {
        String str = "abc";
        String obj(str);
        assert(str == obj);
    }

    {
        String str;
        String obj(str);
        assert(str == obj);
    }

    {
        String str = "hello world hellooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo ijofifnak ajoadajdasaodnnd";
        String obj(str);
        assert(str == obj);
    }

    // Test Case 4: Check if the copy constructor correctly copies a string with special characters
    {
        String str = "!)(@(*&^%$$$^*())(*&^%$%^&*((((((((((&@&@^@%!";
        String obj(str);
        assert(str == obj);
    }

    {
        String str = "12345";
        String obj(str);
        assert(str == obj);
    }


    {
        String str1("hello ");
        String str2("world");
        String obj = str1 + str2;
        String copy(obj);
        assert(obj == copy);
    }

    {
        String original("abcdefg");
        String obj = original.substr(2, 4);
        String copy(obj);
        assert(obj == copy);
    }

    std::cout << "All tests passed." << std::endl;
    return 0;
}
