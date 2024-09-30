#include "string.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main()
{
    {
        String str1("hello");
        String str2("world");
        str1.swap(str2);
        assert(str1 == "world");
        assert(str2 == "hello");
    }

    {
        String empty("");
        String nonEmpty("hello");
        empty.swap(nonEmpty);
        assert(empty == "hello");
        assert(nonEmpty == "");
    }

    {
        String empty1("");
        String empty2("");
        empty1.swap(empty2);
        assert(empty1 == "");
        assert(empty2 == "");
    }

    {
        String str("hello");
        String copy(str);
        str.swap(copy);
        assert(str == "hello");
        assert(copy == "hello");
    }

    {
        String shorter("hi");
        String longer("hello");
        shorter.swap(longer);
        assert(shorter == "hello");
        assert(longer == "hi");
    }

    {
        String str1("hello");
        String str2("hello");
        str1.swap(str2);
        assert(str1 == "hello");
        assert(str2 == "hello");
    }

    {
        String empty("");
        String nonEmpty("world");
        nonEmpty.swap(empty);
        assert(empty == "world");
        assert(nonEmpty == "");
    }

    {
        String str1("hello!");
        String str2("world?");
        str1.swap(str2);
        assert(str1 == "world?");
        assert(str2 == "hello!");

    }

    {
        String str1("nnnnnnnnnnnnnnnnnnnnaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa92999999999999999999999999999dna0NFFFFFFFFFFFFF00020004");
        String str2("WoRlD");
        str1.swap(str2);
        assert(str1 == "WoRlD");
        assert(str2 == "nnnnnnnnnnnnnnnnnnnnaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa92999999999999999999999999999dna0NFFFFFFFFFFFFF00020004");
    }

    std::cout << "All tests passed." << std::endl;
    return 0;
}
