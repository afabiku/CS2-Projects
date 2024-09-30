#include "string.hpp"
#include <cassert>
#include <iostream>

int main() {
    {
        String str("hello");
        int index = str.findch(0, 'e');
        assert(index == 1);
    }

    {
        String str("hello");
        int index = str.findch(0, 'x');
        assert(index == -1);
    }

    {
        String str("hello");
        int index = str.findch(0, 'h');
        assert(index == 0);
    }

    {
        String str("hello");
        int index = str.findch(4, 'o');
        assert(index == 4);
    }

    {
        String str("hello");
        int index = str.findch(-1, 'h');
        assert(index == -1);
    }

    {
        String str("hello");
        int index = str.findch(10, 'h');
        assert(index == -1);
    }

    std::cout << "All tests passed." << std::endl;
    return 0;
}
