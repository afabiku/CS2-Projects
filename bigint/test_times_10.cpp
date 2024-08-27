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
        bigint bi(7);

        // Test 
        bi = bi.times10(1);

        // Verify
        assert(bi == 70);  
    }

    {
        //------------------------------------------------------
        bigint bi("10");

        // Test 
        bi = bi.times10(5);

        // Verify
        assert(bi == 1000000);  
    }

    {
    //------------------------------------------------------
    bigint bi("0");
    
    // Test 
    bi = bi.times10(1);
    
    // Verify
    assert(bi == "0");
    }

    {
        //------------------------------------------------------
        bigint bi(1);

        // Test 
        bi = bi.times10(1);

        // Verify
        assert(bi == 10);  
    }
    {
        //------------------------------------------------------
        bigint bi(1);

        // Test 
        bi = bi.times10(9);

        // Verify
        assert(bi == 1000000000);  
    }
    
    {
    //------------------------------------------------------
    bigint bi;
    
    // Test 
    bi = bi.times10(1);
    
    // Verify
    assert(bi == "0");
    }

    std::cout << "Done testing times_10" << std::endl;
    return 0;
}

