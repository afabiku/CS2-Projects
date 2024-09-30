#include "string.hpp"
#include <cassert>
#include <iostream>

int main() {

    {
        String str("");
        assert(str.capacity() == 0);  
    }

    {
        String str("hello");
        assert(str.capacity() == 5);  
    }

    {
        String str;
        assert(str.capacity() == 0);  
    }

    {
        String str("hello");
        str += str;
        assert(str.capacity() == 10);  
    }


    {
        String str("");
        assert(str.length() == 0);
    }

    {
        String str("hello");
        assert(str.length() == 5);
    }



    {
        String str;
        assert(str.length() == 0);
    }

    {
        String str("   ");
        assert(str.length() == 3);
    }

    {
        String str(" !@#$%^&*() ");
        assert(str.length() == 12);
    }

    std::cout << "All tests passed." << std::endl;
    return 0;
}
