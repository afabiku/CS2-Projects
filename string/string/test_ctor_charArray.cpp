#include "string.hpp"
#include <cassert>
#include <iostream>

int main() {
    {
        const char array[] = "Testing Character Array";
        String str(array);
        assert(str == "Testing Character Array");
    }

    {
        const char array[] = "";
        String str(array);
        assert(str == "");
        assert(str.length() == 0);
    }

    {
        const char array[] = "X";
        String str(array);
        assert(str == "X");
        assert(str.length() == 1);
    }

    {
        const char array[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. "
                             "Integer nec odio. Praesent libero. Sed cursus ante dapibus diam. "
                             "Sed nisi. Nulla quis sem at nibh elementum imperdiet. Duis sagittis "
                             "ipsum. Praesent mauris. Fusce nec tellus sed augue semper porta. "
                             "Mauris massa. Vestibulum lacinia arcu eget nulla.";
        String str(array);
        assert(str == array);
    }

    {
        String a("a"),b("b"),c;
        c = a + b;
        assert(c == "ab");
    }

    std::cout << "All tests passed." << std::endl;
    return 0;
}
