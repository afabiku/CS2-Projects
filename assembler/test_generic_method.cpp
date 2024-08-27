//  Stack class test program
//
//  Tests: XXX 
//

#include "stack.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main()
{
    {
        stack<int> x;
        assert(x.empty());
    }
    {
        stack<int> x;
        x.push(42);

        stack<int> y(x);
        assert(x.top() == y.top());
    }

    {
        stack<double> x;
        x.push(42);
        x.push(84);
        x.push(126);

        x.~stack();
        assert(x.empty());
    }

    {
        stack<int> x;
        x.push(42);
        x.push(84);

        stack<int> y;
        y.push(10);
        y.push(20);

        x.swap(y);
        assert(x.top() == 10 && y.top() == 42);
    }

    {
        stack<String> x;
        x.push("42");

        stack<String> y;
        y = x;

        assert(x.top() == y.top());
    }


    {
        stack<String> x;
        x.push("42");
        assert(!x.empty());
    }

    {
        stack<int> x;
        assert(!x.full());
    }

    {
        stack<int> x;
        x.push(42);
        assert(x.top() == 42);
    }

    {
        stack<int> x;
        x.push(42);
        int value = x.pop();
        assert(value == 42 && x.empty());
    }

    {
        stack<int> x;
        x.push(42);
        assert(!x.empty());
    }


    return 0;
}

