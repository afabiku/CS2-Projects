#include "string.hpp"
#include <cassert>
#include <iostream>
 
//===========================================================================
int main ()
{
    {
        String str;
        assert(str.length() == 0);
    }

    {
        String str;
        assert(str == "");
    }

    {
        char singleChar = 'A';
        String str(singleChar);

        assert(str == 'A');
    }

    {
        char singleChar = '1';
        String str(singleChar);

        assert(str == '1');
    }

    {
        const char array[] = "Hello";
        String str(array);

        assert(str == "Hello");
    }

    {
        const char array[] = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
        String str(array);

        assert(str == "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
    }
    std::cout << "All tests passed." << std::endl;
    return 0;
}
