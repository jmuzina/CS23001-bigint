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
		bigint bi;

		assert(bi[0] == 0);
		assert(bi[CAPACITY - 1] == 0);
	}

	{
		bigint bi(0);
		
		assert(bi[0] == 0);
		assert(bi[CAPACITY - 1] == 0);
	}

	{
		bigint bi(1);

		assert(bi[0] == 1);
		assert(bi[CAPACITY - 1] == 0);
	}

	{
		bigint bi(8675309);

		assert(bi[0] == 8);
		assert(bi[1] == 6);
		assert(bi[5] == 0);
		assert(bi[6] == 9);
	}

	{
		bigint bi("12345678901234567890");

		assert(bi[0] == 1);
		assert(bi[11] == 2);
		assert(bi[19] == 0);
	}

	{
		bigint bi("1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456");

		assert(bi[0] == 1);
		assert(bi[99] == 0);
		assert(bi[175] == 6);
		assert(bi[255] == 6);
	}
	std::cout << "Done testing subscript." << std::endl;
}