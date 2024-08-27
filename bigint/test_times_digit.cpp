// bigint Test Program
//
// Tests:  times_10, uses ==
//
// NEED TO IMPLEMENT
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3);

        // Test 
        bi = bi.timesDigit(1);

        // Verify
        assert(bi == 3);  
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3);

        // Test 
        bi = bi.timesDigit(0);

        // Verify
        assert(bi == 0); 
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(12);

        // Test 
        bi = bi.timesDigit(9);

        // Verify
        assert(bi == 108);  
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(12);

        // Test 
        bi = bi.timesDigit(9);

        // Verify
        assert(bi == 108); 
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(455631);

        // Test 
        bi = bi.timesDigit(2);

        // Verify
        assert(bi == 911262); 
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi;

        // Test 
        bi = bi.timesDigit(2);

        // Verify
        assert(bi == 0); 
    }


    //Add test cases as needed.
    
    std::cout << "Done testing bigint * digit" << std::endl;
    return 0;
}
