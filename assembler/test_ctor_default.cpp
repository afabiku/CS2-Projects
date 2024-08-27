#include "stack.hpp"
#include <cassert>
#include <iostream>
int main()
{
    {
        stack<String> x;
        assert(x.empty());
    }
    
    {
        stack<int> x;
        assert(x.empty());
    }

    {
        stack<double> x;
        assert(x.empty());
    }

    {
        stack<bool> x;
        assert(x.empty());
    }
       
    return 0;
}
