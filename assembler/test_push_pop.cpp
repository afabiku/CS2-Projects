
#include "stack.hpp"
#include <cassert>
#include <iostream>

int main()
{
    {
        stack<int> x;
        x.push(10);
        x.push(20);
        x.push(30);

        assert(x.pop() == 30);
        assert(x.pop() == 20);
        assert(x.pop() == 10);
        assert(x.empty());
    }



    {
        stack<char> x;
        x.push('A');
        x.push('B');
        x.push('C');

        assert(x.pop() == 'C');
        assert(x.pop() == 'B');
        assert(x.pop() == 'A');
        assert(x.empty());
    }

    {
        stack<bool> x;
        x.push(true);
        x.push(false);
        x.push(true);

        assert(x.pop() == true);
        assert(x.pop() == false);
        assert(x.pop() == true);
        assert(x.empty());
    }

    {
        stack<String> x;
        x.push("true");
        x.push("false");
        x.push("true");

        assert(x.pop() == "true");
        assert(x.pop() == "false");
        assert(x.pop() == "true");
        assert(x.empty());
    }

        {
        stack<String> x;
        x.push("looooooooooooooooooooooooooooooooooooonggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg");
        x.push("looooooooooooooooooooooooooooooooooooonggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggglooooooooooooooooooooooooooooooooooooonggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg");
        x.push("looooooooooooooooooooooooooooooooooooonggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggglooooooooooooooooooooooooooooooooooooonggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggglooooooooooooooooooooooooooooooooooooonggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggglooooooooooooooooooooooooooooooooooooonggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg");

        assert(x.pop() == "looooooooooooooooooooooooooooooooooooonggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggglooooooooooooooooooooooooooooooooooooonggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggglooooooooooooooooooooooooooooooooooooonggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggglooooooooooooooooooooooooooooooooooooonggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg");
        assert(x.pop() == "looooooooooooooooooooooooooooooooooooonggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggglooooooooooooooooooooooooooooooooooooonggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg");
        assert(x.pop() == "looooooooooooooooooooooooooooooooooooonggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg");
        assert(x.empty());
    }
    return 0;
}
