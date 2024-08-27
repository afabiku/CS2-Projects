#include "stack.hpp"
#include <cassert>
#include <iostream>
int main()
{
    {
        stack<int> x;
        x.~stack();
        assert(x.empty());
    }

    {
        stack<String> x;
        x.~stack();
        assert(x.empty());
    }

    {
        stack<int> x;
        x.push(10);
        x.push(20);
        x.push(30);
        x.push(40);

        stack<String> y;
        y.push("sam");
        y.push("a");
        y.push("!");

        x.~stack(); 
        y.~stack(); 

        assert(x.empty()); 
        assert(y.empty()); 
    }


    {
        stack<int> x;
        for (int i = 0; i < 99999; ++i) {
            x.push(i);
        }

        x.~stack();
        assert(x.empty());
    }


    {
        class MyClass {
        public:
            int data;
            MyClass(int d) : data(d) {}
        };

        stack<MyClass> x;
        x.push(MyClass(1));
        x.push(MyClass(2));
        x.push(MyClass(3));

        x.~stack(); 
        assert(x.empty());
    }


    return 0;
}
