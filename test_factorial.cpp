/**
* Joseph Muzina
* Project 1 - bigint
* CS 23001
*/

#include "bigint.hpp"
#include <cassert>

int main() {
	std::cout << "Started factorial unit test.\nNOTE: this";
	std::cout << " test involves calculations of VERY large";
	std::cout << " numbers and may take up to 20 seconds.\n";
	{
		bigint bi;
		bigint result(bi.factorial());

		assert(0 == result);
	}
	{
		bigint bi(1);
		bigint result(bi.factorial());

		assert(1 == result);
	}
	{
		bigint bi(2);
		bigint result(bi.factorial());

		assert(2 == result);
	}
	{
		bigint bi(5);
		bigint result(bi.factorial());

		assert(120 == result);
	}
	{
		bigint bi(16);
		bigint result(bi.factorial());
		bigint answer("20922789888000");

		assert(answer == result);
	}
	{
		bigint bi(45);
		bigint result(bi.factorial());
		bigint answer("119622220865480194561963161495657715064383733760000000000");

		assert(answer == result);
	}
	{
		bigint bi(300);
		bigint result(bi.factorial());
		bigint answer("306057512216440636035370461297268629388588804173576999416776741259476533176716867465515291422477573349939147888701726368864263907759003154226842927906974559841225476930271954604008012215776252176854255965356903506788725264321896264299365204576448830388909753943489625436053225980776521270822437639449120128678675368305712293681943649956460498166450227716500185176546469340112226034729724066333258583506870150169794168850353752137554910289126407157154830282284937952636580145235233156936482233436799254594095276820608062232812387383880817049600000000000000000000000000000000000000000000000000000000000000000000000000");
			
		assert(answer == result);
	}
	std::cout << "Done testing factorial\n";
	return 0;
}
