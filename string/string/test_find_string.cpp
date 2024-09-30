#include "string.hpp"
#include <cassert>
#include <iostream>

int main() {
    {
        String str("hello world");
        int index = str.findstr(0, "world");
        assert(index == 6);
    }

    {
        String str("hello world, hello alex");
        int index = str.findstr(0, "hello");
        assert(index == 0);
    }

    // Test Case 3: Search for a substring in a string where the substring does not exist.
    {
        String str("hello world");
        int index = str.findstr(0, "alex");
        assert(index == -1);
    }

    {
        String str("hello world alex");
        String substr("ex");
        int index = str.findstr(0, substr);
        assert(index == 14);
    }

    {
        String str("hello world");
        String substr(" ");
        int index = str.findstr(0, substr);
        assert(index == 5);
    }

    {
        String str("hello world");
        String substr("world");
        int index = str.findstr(12, substr);
        assert(index == -1);
    }

    std::cout << "All tests passed." << std::endl;
    return 0;
}
