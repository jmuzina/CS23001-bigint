/**
* Joseph Muzina
* Project 1 - bigint
* CS 23001
*/

#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    bigint bi;

    // Verify
    std::cout << "0 == " << bi << std::endl;
    assert(bi == 0);

    std::cout << "Done testing default constructor." << std::endl;
}