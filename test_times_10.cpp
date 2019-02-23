/**
* Joseph Muzina
* Project 1 - bigint
* CS 23001
*/

#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main() {
	{
		bigint bi(0);
		bigint result(bi.times10(0));

		assert(bi == 0);
		assert(result == 0);
	}

	{
		bigint bi(0);
		bigint result(bi.times10(1));


		assert(bi == 0);
		assert(result == 0);
	}

	// When RHS is 0, no numbers are shifted
	{
		bigint bi(1);
		bigint result(bi.times10(0));

		assert(bi == 1);
		assert(result == 1);
	}

	{
		bigint bi(1);
		bigint result(bi.times10(1));

		assert(bi == 1);
		assert(result == 10);
	}

	{
		bigint bi(1);
		bigint result(bi.times10(2));

		assert(bi == 1);
		assert(result == 100);
	}

	{
		bigint bi(52);
		bigint result(bi.times10(2));

		assert(bi == 52);
		assert(result == 5200);
	}

	{
		bigint bi(75);
		bigint result(bi.times10(5));

		assert(bi == 75);
		assert(result == 7500000);
	}

	{
		bigint bi("8675309");
		bigint result(bi.times10(2));

		assert(bi == 8675309);
		assert(result == 867530900);
	}

	{
		bigint bi("12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890");
		bigint result(bi.times10(50));
		bigint answer("1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789000000000000000000000000000000000000000000000000000");

		assert(result == answer);
	}

	std::cout << "Done testing times10" << std::endl;
}
