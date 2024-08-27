#include "stack.hpp"
#include <cassert>
#include <iostream>
int main()
{
    {
        stack<int> x;
        stack<int> y;  
        x = y;
        assert(x.empty());
        assert(y.empty());

    }

    {
        stack<int> x;
        stack<int> y;  
        stack<int> z;
        x = y = z;
        assert(x.empty());
        assert(y.empty());
        assert(z.empty());


    }

    {
        stack<double> x;
        stack<double> y;
        y.push(42);
        x = y;
        assert(!x.empty() && x.top() == 42 && !y.empty());
    }

    {
        stack<int> x;
        x.push(42);
        stack<int> y;
        x = y;
        assert(x.empty() && y.empty());
    }

    {
        stack<int> x;
        x.push(42);
        x.push(84);
        stack<int> y;
        y.push(10);
        y.push(20);
        y.push(30);
        x = y;
        assert(x.pop() == 30 && y.pop() == 30);
        assert(x.pop() == 20 && y.pop() == 20);
        assert(x.pop() == 10 && y.pop() == 10);

    }

    {
        stack<int> x;
        x.push(42);
        x = x;
        assert(x.top() == 42);
    }

    {
        stack<int> x;
        x = x;
        assert(x.empty());
    }

    {
        stack<String> x;
        String a;
        String b("abc");
        x.push(a);
        x.push(b);

        stack<String> y;
        y.push(10);

        y = x;

        assert(x.pop() == "abc");
        assert(x.pop() == a);

    }
    {
        stack<int> x;
        stack<int>y;
        for(int i = 0; i < 99999999; ++i){
            x.push(i);
        }
        y = x;
        for(int i = 0; i < 99999999; ++i){
            assert(x.pop() == y.pop());
        }
    }

    return 0;
}
