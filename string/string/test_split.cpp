#include "string.hpp"
#include <vector>
#include <cassert>

//===========================================================================
int main()
{
    {
        String str("");
        std::vector<String> result = str.split(' ');
        assert(result.size() == 1);
        assert(result[0] == "");
    }

    {
        String str("hello world");
        std::vector<String> result = str.split('@');
        assert(result.size() == 1);
        assert(result[0] == "hello world");
    }

    {
        String str("apple,banana,orange,apple,banana");
        std::vector<String> result = str.split(',');
        assert(result.size() == 5);
        assert(result[0] == "apple");
        assert(result[1] == "banana");
        assert(result[2] == "orange");
        assert(result[3] == "apple");
        assert(result[4] == "banana");
    }

    {
        String str("one,,two,,three");
        std::vector<String> result = str.split(',');
        assert(result.size() == 5);
        assert(result[0] == "one");
        assert(result[1] == "");
        assert(result[2] == "two");
        assert(result[3] == "");
        assert(result[4] == "three");
    }

    {
        String str(",hello,world");
        std::vector<String> result = str.split(',');
        assert(result.size() == 3);
        assert(result[0] == "");
        assert(result[1] == "hello");
        assert(result[2] == "world");
    }

    {
        String str("hello,world,");
        std::vector<String> result = str.split(',');
        assert(result.size() == 3);
        assert(result[0] == "hello");
        assert(result[1] == "world");
        assert(result[2] == "");
    }

    {
        String str("apple::banana::orange");
        std::vector<String> result = str.split("::");
        assert(result.size() == 3);
        assert(result[0] == "apple");
        assert(result[1] == "banana");
        assert(result[2] == "orange");
    }

    {
        String str("hello world");
        std::vector<String> result = str.split(' ');
        assert(result.size() == 2);
        assert(result[0] == "hello");
        assert(result[1] == "world");
    }

    {
        String str("::hello::world::");
        std::vector<String> result = str.split("::");
        assert(result.size() == 4);
        assert(result[0] == "");
        assert(result[1] == "hello");
        assert(result[2] == "world");
        assert(result[3] == "");
    }

    {
        String str("::hello::::world::");
        std::vector<String> result = str.split("::");
        assert(result.size() == 6);
        assert(result[0] == "");
        assert(result[1] == "hello");
        assert(result[2] == "");
        assert(result[3] == "");
        assert(result[4] == "world");
        assert(result[5] == "");
    }

    std::cout << "Passed all test cases" << std::endl;
    return 0;
}
