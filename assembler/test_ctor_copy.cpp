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
        stack<int> y(x);
        assert(x.empty() && y.empty());
    }
    {
        stack<String> x;
        stack<String> y(x);
        assert(x.empty() && y.empty());
    }

    {
        stack<int> x;
        x.push(42);

        stack<int> y(x);
        assert(x.top() == y.top());
    }

    {
        stack<int> x;
        x.push(10);
        x.push(20);
        x.push(30);

        stack<int> y(x);
        assert(x.pop() == y.pop());
        assert(x.pop() == y.pop());
        assert(x.pop() == y.pop());
    }


    {
        stack<bool> x;
        x.push(true);
        x.push(false);

        stack<bool> y(x);
        assert(x.pop() == y.pop());
        assert(x.pop() == y.pop());
    }

    {
        stack<int> x;
        for (int i = 0; i < 1000; ++i) {
            x.push(i);
        }

        stack<int> y(x);
        for (int i = 0; i < 1000; ++i) {
            assert(x.pop() == y.pop());
        }
    }
    {
        stack<int> x;
        x.push(-10);
        x.push(-20);
        x.push(-30);

        stack<int> y(x);
        assert(x.pop() == y.pop());
        assert(x.pop() == y.pop());
        assert(x.pop() == y.pop());
    }

    {
        stack<String> x;
        x.push("10");
        x.push("20");
        x.push("30");

        stack<String> y(x);
        assert(x.pop() == y.pop());
        assert(x.pop() == y.pop());
        assert(x.pop() == y.pop());

    }


    return 0;
}

