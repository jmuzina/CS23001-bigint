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
		bigint result(bi.timesDigit(0));

		assert(bi == 0);
		assert(result == 0);
	}

	{
		bigint bi(0);
		bigint result(bi.timesDigit(1));

		assert(bi == 0);
		assert(result == 0);
	}

	{
		bigint bi(1);
		bigint result(bi.timesDigit(0));

		assert(bi == 1);
		assert(result == 0);
	}

	{
		bigint bi(1);
		bigint result(bi.timesDigit(1));

		assert(bi == 1);
		assert(result == 1);
	}

	{
		bigint bi(1);
		bigint result(bi.timesDigit(2));

		assert(bi == 1);
		assert(result == 2);
	}

	{
		bigint bi(5);
		bigint result(bi.timesDigit(2));

		assert(bi == 5);
		assert(result == 10);
	}

	{
		bigint bi(10);
		bigint result(bi.timesDigit(6));

		assert(bi == 10);
		assert(result == 60);
	}

	{
		bigint bi(4387);
		bigint result(bi.timesDigit(2));

		assert(bi == 4387);
		assert(result == 8774);
	}

	{
		bigint bi("82745890273456354876");
		bigint result(bi.timesDigit(9));
		bigint answer("744713012461107193884");

		assert(result == answer);
	}
	std::cout << "Done testing bigint * digit" << std::endl;
}
