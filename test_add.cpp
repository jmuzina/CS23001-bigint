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
		//------------------------------------------------------
		// Setup fixture
		bigint left(0);
		bigint right(0);
		bigint result;

		// Test 
		result = left + right;

		// Verify
		assert(left == 0);
		assert(right == 0);
		assert(result == 0);
	}

	{
		//------------------------------------------------------
		// Setup fixture
		bigint left(1);
		bigint right(0);
		bigint result;

		// Test
		result = left + right;

		// Verify
		assert(left == 1);
		assert(right == 0);
		assert(result == 1);
	}
	{
		//------------------------------------------------------
		// Setup fixture
		bigint left(1);
		bigint right(1);
		bigint result;

		// Test
		result = left + right;

		// Verify
		assert(left == 1);
		assert(right == 1);
		assert(result == 2);
	}

	{
		bigint left("45934758");
		bigint right("502904986");
		bigint result = left + right;
		int sum = 548839744;

		assert(left == 45934758);
		assert(right == 502904986);
		assert(result == sum);
	}

	{
		bigint left("10000000000000000000000000000000000000000000000000000000000000000000000");
		bigint right("40000000000000000000000000000000000000000000000000000000000000000000000");
		bigint result("50000000000000000000000000000000000000000000000000000000000000000000000");

		bigint sum = left + right;

		assert(result == sum);
	}

	{
		bigint left("1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456");
		bigint right("58239485923405798547698437505824309860384576983457038750693095860348756345345");
		bigint result("1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678959474053813529255336710783184725544428274700440246051096371997094916646468801");

		bigint sum = left + right;

		assert(result == sum);
	}

	std::cout << "Done with testing addition." << std::endl;
}