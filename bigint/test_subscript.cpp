// bigint Test Program
//
// Tests:  subscript, uses ==
//
// NEED TO IMPLEMENT
// 
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    
    {
        // Setup
        bigint bi(4);

        // Test 
        int digit = bi[0];

        // Verify
        assert(bi    == digit);  
        //assert(digit == 250);
    }
    
    //Add test cases!!
    {
        // Setup
        bigint bi(1234);

        // Test 
        int digit = bi[3];

        // Verify
        assert(digit == 1);
    }

    {
        // Setup
        bigint bi(123456789);

        // Test 
        int digit = bi[8];

        // Verify
        assert(digit == 1);
    }

    std::cout << "Done testing subscript." << std::endl;
    return 0;
}

