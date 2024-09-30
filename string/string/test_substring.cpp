#include "string.hpp"
#include <cassert>
#include <iostream>

int main() {
    {
        String str("hello world");
        String substr = str.substr(3, 7);
        assert(substr == "lo wo");
    }

    // Test Case 2: Substring starting from the beginning of the string.
    {
        String str("hello world");
        String substr = str.substr(0, 4);
        assert(substr == "hello");
    }

    // Test Case 3: Substring ending at the end of the string.
    {
        String str("hello world");
        String substr = str.substr(6, 10);
        assert(substr == "world");
    }

    // Test Case 4: Substring with negative start index (start from the beginning of the string).
    {
        String str("hello world");
        String substr = str.substr(-3, 7);
        assert(substr == "hello wo");
    }

    // Test Case 5: Substring with end index beyond the end of the string (end at the end of the string).
    {
        String str("hello world");
        String substr = str.substr(6, 15);
        assert(substr == "world");
    }

    std::cout << "All tests passed." << std::endl;
    return 0;
}
